/**
 * Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
 * more contributor license agreements. See the NOTICE file distributed
 * with this work for additional information regarding copyright ownership.
 * Green Energy Corp licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This project was forked on 01/01/2013 by Automatak, LLC and modifications
 * may have been made to this file. Automatak, LLC licenses these modifications
 * to you under the terms of the License.
 */
#include "OutstationStackImpl.h"

#include <future>

using namespace opendnp3;

namespace asiodnp3
{

OutstationStackImpl::OutstationStackImpl(
	openpal::LogRoot& root,
    openpal::IExecutor& executor,
	opendnp3::ITimeWriteHandler& timeWriteHandler,
	opendnp3::ICommandHandler& commandHandler,
    const OutstationStackConfig& config,
    const StackActionHandler& handler_) :	
	
	handler(handler_),
	stack(root, &executor, &statistics, config.link),
	databaseBuffers(config.dbTemplate),
	eventBuffers(config.eventBuffer),
	mutex(),
	database(databaseBuffers.GetFacade(), &mutex),
	outstation(config.outstation, executor, root, stack.transport, commandHandler, timeWriteHandler, database, eventBuffers.GetFacade())
{
	stack.transport.SetAppLayer(&outstation);
}

IMeasurementLoader* OutstationStackImpl::GetLoader()
{
	return &database;
}

void OutstationStackImpl::Enable()
{
	handler.EnableRoute(&stack.link);
}

void OutstationStackImpl::Disable()
{
	handler.DisableRoute(&stack.link);
}

void OutstationStackImpl::BeginShutdown()
{
	handler.BeginShutdown(&stack.link, this);
}

StackStatistics OutstationStackImpl::GetStackStatistics()
{
	std::promise<StackStatistics> p;
	auto lambda = [&]() { p.set_value(statistics); };
	handler.GetExecutor()->PostLambda(lambda);
	return p.get_future().get();
}

openpal::IExecutor* OutstationStackImpl::GetExecutor()
{
	return handler.GetExecutor();
}

void OutstationStackImpl::SetNeedTimeIIN()
{	
	auto lambda = [this]() { this->outstation.SetRequestTimeIIN(); };
	handler.GetExecutor()->PostLambda(lambda);
}

void OutstationStackImpl::SetLinkRouter(opendnp3::ILinkRouter* pRouter)
{
	stack.link.SetRouter(pRouter);
}

opendnp3::ILinkContext* OutstationStackImpl::GetLinkContext()
{
	return &stack.link;
}

}

