/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://ogre.sourceforge.net/

Copyright � 2000-2005 The OGRE Team
Also see acknowledgements in Readme.html

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
-----------------------------------------------------------------------------
*/
#include "OgreStableHeaders.h"
#include "OgreHardwarePixelBuffer.h"
#include "OgreImage.h"
#include "OgreException.h"

namespace Ogre 
{
  
    //-----------------------------------------------------------------------------    
    HardwarePixelBuffer::HardwarePixelBuffer(size_t width, size_t height, size_t depth,
            PixelFormat format,
            HardwareBuffer::Usage usage, bool useSystemMemory, bool useShadowBuffer):
        HardwareBuffer(usage, useSystemMemory, useShadowBuffer),
        mWidth(width), mHeight(height), mDepth(depth),
        mFormat(format)
    {
        // Default
        mRowPitch = mWidth;
        mSlicePitch = mHeight*mWidth;
    }
    
    //-----------------------------------------------------------------------------    
    HardwarePixelBuffer::~HardwarePixelBuffer()
    {
    }
    
    //-----------------------------------------------------------------------------    
    void* HardwarePixelBuffer::lock(size_t offset, size_t length, LockOptions options)
    {
        assert(!isLocked() && "Cannot lock this buffer, it is already locked!");
        assert(offset == 0 && length == mSize && "Cannot lock memory region, most lock box or entire buffer");
        
        Image::Box myBox(0, 0, 0, mWidth, mHeight, mDepth);
        const PixelBox &rv = lock(myBox, options);
        return rv.data;
    }
    
    //-----------------------------------------------------------------------------    
    const PixelBox &HardwarePixelBuffer::lock(const Image::Box lockBox, LockOptions options)
    {
        void* ret;
        if (mUseShadowBuffer)
        {
            if (options != HBL_READ_ONLY)
            {
                // we have to assume a read / write lock so we use the shadow buffer
                // and tag for sync on unlock()
                mShadowUpdated = true;
            }

            mCurrentLock = static_cast<HardwarePixelBuffer*>(mpShadowBuffer)->lock(lockBox, options);
        }
        else
        {
            // Lock the real buffer if there is no shadow buffer 
            mCurrentLock = lockImpl(lockBox, options);
            mIsLocked = true;
        }

        return mCurrentLock;
    }
    
    //-----------------------------------------------------------------------------    
    const PixelBox &HardwarePixelBuffer::getCurrentLock() { 
        assert(isLocked() && "Cannot get current lock: buffer not locked");
        
        return mCurrentLock; 
    }
    
    //-----------------------------------------------------------------------------    
    /// Internal implementation of lock()
    void* HardwarePixelBuffer::lockImpl(size_t offset, size_t length, LockOptions options)
    {
        Except(Exception::ERR_INTERNAL_ERROR, "lockImpl(offset,length) is not valid for PixelBuffers and should never be called",
            "HardwarePixelBuffer::lockImpl");
    }
    
    //-----------------------------------------------------------------------------    
    
    HardwarePixelBufferSharedPtr::HardwarePixelBufferSharedPtr(HardwarePixelBuffer* buf)
        : SharedPtr<HardwarePixelBuffer>(buf)
    {

    }    
};