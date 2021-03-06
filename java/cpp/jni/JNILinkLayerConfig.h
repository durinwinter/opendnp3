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

#ifndef OPENDNP3JAVA_JNILINKLAYERCONFIG_H
#define OPENDNP3JAVA_JNILINKLAYERCONFIG_H

#include <jni.h>

#include "../adapters/LocalRef.h"

namespace jni
{
    struct JCache;

    namespace cache
    {
        class LinkLayerConfig
        {
            friend struct jni::JCache;

            bool init(JNIEnv* env);
            void cleanup(JNIEnv* env);

            public:

            // field getter methods
            jboolean getisMaster(JNIEnv* env, jobject instance);
            LocalRef<jobject> getkeepAliveTimeout(JNIEnv* env, jobject instance);
            jint getlocalAddr(JNIEnv* env, jobject instance);
            jint getnumRetry(JNIEnv* env, jobject instance);
            jint getremoteAddr(JNIEnv* env, jobject instance);
            LocalRef<jobject> getresponseTimeout(JNIEnv* env, jobject instance);
            jboolean getuseConfirms(JNIEnv* env, jobject instance);

            private:

            jclass clazz = nullptr;

            // field ids
            jfieldID isMasterField = nullptr;
            jfieldID useConfirmsField = nullptr;
            jfieldID numRetryField = nullptr;
            jfieldID localAddrField = nullptr;
            jfieldID remoteAddrField = nullptr;
            jfieldID responseTimeoutField = nullptr;
            jfieldID keepAliveTimeoutField = nullptr;
        };
    }
}

#endif
