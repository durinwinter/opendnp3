//
//  _   _         ______    _ _ _   _             _ _ _
// | \ | |       |  ____|  | (_) | (_)           | | | |
// |  \| | ___   | |__   __| |_| |_ _ _ __   __ _| | | |
// | . ` |/ _ \  |  __| / _` | | __| | '_ \ / _` | | | |
// | |\  | (_) | | |___| (_| | | |_| | | | | (_| |_|_|_|
// |_| \_|\___/  |______\__,_|_|\__|_|_| |_|\__, (_|_|_)
//                                           __/ |
//                                          |___/
// 
// This file is auto-generated. Do not edit manually
// 
// Copyright 2013-2019 Automatak, LLC
// 
// Licensed to Green Energy Corp (www.greenenergycorp.com) and Automatak
// LLC (www.automatak.com) under one or more contributor license agreements.
// See the NOTICE file distributed with this work for additional information
// regarding copyright ownership. Green Energy Corp and Automatak LLC license
// this file to you under the Apache License, Version 2.0 (the "License"); you
// may not use this file except in compliance with the License. You may obtain
// a copy of the License at:
// 
//   http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "JNIHeaderInfo.h"

namespace jni
{
    namespace cache
    {
        bool HeaderInfo::init(JNIEnv* env)
        {
            auto clazzTemp = env->FindClass("Lcom/automatak/dnp3/HeaderInfo;");
            this->clazz = (jclass) env->NewGlobalRef(clazzTemp);
            env->DeleteLocalRef(clazzTemp);

            this->init6Constructor = env->GetMethodID(this->clazz, "<init>", "(Lcom/automatak/dnp3/enums/GroupVariation;Lcom/automatak/dnp3/enums/QualifierCode;Lcom/automatak/dnp3/enums/TimestampMode;ZZI)V");
            if(!this->init6Constructor) return false;

            return true;
        }

        void HeaderInfo::cleanup(JNIEnv* env)
        {
            env->DeleteGlobalRef(this->clazz);
        }

        LocalRef<jobject> HeaderInfo::init6(JNIEnv* env, jobject arg0, jobject arg1, jobject arg2, jboolean arg3, jboolean arg4, jint arg5)
        {
            return LocalRef<jobject>(env, env->NewObject(this->clazz, this->init6Constructor, arg0, arg1, arg2, arg3, arg4, arg5));
        }
    }
}
