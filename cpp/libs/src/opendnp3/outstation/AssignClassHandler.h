/*
 * Copyright 2013-2019 Automatak, LLC
 *
 * Licensed to Green Energy Corp (www.greenenergycorp.com) and Automatak
 * LLC (www.automatak.com) under one or more contributor license agreements.
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. Green Energy Corp and Automatak LLC license
 * this file to you under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef OPENDNP3_ASSIGNCLASSHANDLER_H
#define OPENDNP3_ASSIGNCLASSHANDLER_H

#include <openpal/executor/IExecutor.h>
#include <openpal/logging/Logger.h>

#include "opendnp3/app/parsing/IAPDUHandler.h"
#include "opendnp3/gen/AssignClassType.h"
#include "opendnp3/outstation/IClassAssigner.h"
#include "opendnp3/outstation/IOutstationApplication.h"

namespace opendnp3
{

class AssignClassHandler : public IAPDUHandler
{
public:
    AssignClassHandler(openpal::IExecutor& executor, IOutstationApplication& application, IClassAssigner& assigner);

    virtual bool IsAllowed(uint32_t headerCount, GroupVariation gv, QualifierCode qc) override final
    {
        return true;
    }

private:
    virtual IINField ProcessHeader(const AllObjectsHeader& header) override final;

    virtual IINField ProcessHeader(const RangeHeader& header) override final;

    IINField RecordClass(GroupVariation gv);

    bool IsExpectingAssignment();

    IINField ProcessAssignAll(AssignClassType type, PointClass clazz);

    IINField ProcessAssignRange(AssignClassType type, PointClass clazz, const Range& range);

    void NotifyApplicationOfAssignment(AssignClassType type, PointClass clazz, const Range& range);

    int32_t classHeader;
    PointClass clazz;

    openpal::IExecutor* pExecutor;
    IOutstationApplication* pApplication;
    IClassAssigner* pAssigner;
};

} // namespace opendnp3

#endif
