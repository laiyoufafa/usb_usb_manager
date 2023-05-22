/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "usb_common_test.h"

using namespace OHOS::Security::AccessToken;

namespace OHOS {
namespace USB {
namespace Common {
TokenInfoParams g_normalInfoInstance = {
    .dcapsNum = 0,
    .permsNum = 0,
    .aclsNum = 0,
    .dcaps = nullptr,
    .perms = nullptr,
    .acls = nullptr,
    .processName = "usb_manager",
    .aplStr = "normal",
};

TokenInfoParams g_sysInfoInstance = {
    .dcapsNum = 0,
    .permsNum = 0,
    .aclsNum = 0,
    .dcaps = nullptr,
    .perms = nullptr,
    .acls = nullptr,
    .processName = "usb_manager",
    .aplStr = "system_basic",
};

void UsbCommonTest::SetTestCaseNative(TokenInfoParams *infoInstance)
{
    uint64_t tokenId = GetAccessTokenId(infoInstance);
    int ret = SetSelfTokenID(tokenId);
    if (ret == 0) {
        HDF_LOGI("SetSelfTokenID success");
    } else {
        HDF_LOGE("SetSelfTokenID fail");
    }
    AccessTokenKit::ReloadNativeTokenInfo();
}

void UsbCommonTest::GrantPermissionSysNative()
{
    SetTestCaseNative(&g_sysInfoInstance);
}

void UsbCommonTest::GrantPermissionNormalNative()
{
    SetTestCaseNative(&g_normalInfoInstance);
}
} // namespace Common
} // namespace USB
} // namespace OHOS
