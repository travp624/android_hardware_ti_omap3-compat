/*
 * Copyright (C) Texas Instruments - http://www.ti.com/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
* @file CameraProperties.cpp
*
* This file maps the CameraHardwareInterface to the Camera interfaces on OMAP4 (mainly OMX).
*
*/

//#include "CameraHal.h"

#define LOG_TAG "CameraProperties"

#include <utils/threads.h>

#include "DebugUtils.h"
#include "CameraProperties.h"

#define CAMERA_ROOT         "CameraRoot"
#define CAMERA_INSTANCE     "CameraInstance"

namespace android {

// lower entries have higher priority
static const char* g_camera_adapters[] = {
#ifdef OMAP4_SUPPORT_OMX_CAMERA_ADAPTER
    "libomxcameraadapter.so",
#endif
#ifdef OMAP4_SUPPORT_USB_CAMERA_ADAPTER
    "libusbcameraadapter.so"
#endif
};

/*********************************************************
 CameraProperties - public function implemetation
**********************************************************/

CameraProperties::CameraProperties() : mCamerasSupported(0)
{
    LOG_FUNCTION_NAME;

    mCamerasSupported = 0;
    mInitialized = 0;

    LOG_FUNCTION_NAME_EXIT;
}

CameraProperties::~CameraProperties()
{
    LOG_FUNCTION_NAME;

    LOG_FUNCTION_NAME_EXIT;
}


// Initializes the CameraProperties class
status_t CameraProperties::initialize()
{
    LOG_FUNCTION_NAME;

    status_t ret;

    Mutex::Autolock lock(mLock);

    if(mInitialized)
        return NO_ERROR;

    ret = loadProperties();

    mInitialized = 1;

    LOG_FUNCTION_NAME_EXIT;

    return ret;
}

/* Added by Madhu */
int CameraProperties::getCapabilities(CameraProperties::Properties* properties_array,
                                          const unsigned int starting_camera,
                                          const unsigned int max_camera)
{   

    int num_cameras_supported = 0;
    CameraProperties::Properties* properties = NULL;

    LOG_FUNCTION_NAME;

    if(!properties_array)
    {
        return -EINVAL;
    }

    // TODO: Need to tell camera properties what other cameras we can support
    if (starting_camera + num_cameras_supported < max_camera) {
        num_cameras_supported++;
        properties = properties_array + starting_camera;status_t ret = NO_ERROR;
        properties->set(CameraProperties::CAMERA_NAME, "USBCamera");
    }   

    return num_cameras_supported;
}


///Loads all the Camera related properties
status_t CameraProperties::loadProperties()
{
    LOG_FUNCTION_NAME;

    status_t ret = NO_ERROR;

    // adapter updates capabilities and we update camera count
    mCamerasSupported = getCapabilities(mCameraProps, mCamerasSupported, MAX_CAMERAS_SUPPORTED);

    if((int)mCamerasSupported < 0) {
        LOGE("error while getting capabilities");
        ret = UNKNOWN_ERROR;
    } else if (mCamerasSupported > MAX_CAMERAS_SUPPORTED) {
        LOGE("returned too many adapaters");
        ret = UNKNOWN_ERROR;
    } else {
        LOGE("num_cameras = %d", mCamerasSupported);

        for (unsigned int i = 0; i < mCamerasSupported; i++) {
            mCameraProps[i].set(CAMERA_SENSOR_INDEX, i);
            mCameraProps[i].dump();
        }
    }

    LOGV("mCamerasSupported = %d", mCamerasSupported);
    LOG_FUNCTION_NAME_EXIT;
    return ret;
}

// Returns the number of Cameras found
int CameraProperties::camerasSupported()
{
    LOG_FUNCTION_NAME;
    return mCamerasSupported;
}

};
