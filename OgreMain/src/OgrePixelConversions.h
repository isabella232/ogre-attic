/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

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
/** Internal include file -- do not use externally */
using namespace Ogre;

#define FMTCONVERTERID(from,to) (((from)<<8)|(to))


/**
 * Convert a box of pixel from one type to another. Who needs automatic code 
 * generation when we have C++ templates and the policy design pattern.
 * 
 * @param   U       Policy class to facilitate pixel-to-pixel conversion. This class
 *    has at least two typedefs: SrcType and DstType. SrcType is the source element type,
 *    dstType is the destination element type. It also has a static method, pixelConvert, that
 *    converts a srcType into a dstType.
 */
template <class U> struct PixelBoxConverter 
{
    static const int ID = U::ID;
    static void conversion(const PixelBox &src, const PixelBox &dst)
    {
        typename U::SrcType *srcptr = static_cast<typename U::SrcType*>(src.data);
        typename U::DstType *dstptr = static_cast<typename U::DstType*>(dst.data);
        unsigned int srcSliceSkip = src.getSliceSkip();
        unsigned int dstSliceSkip = dst.getSliceSkip();
        for(unsigned int z=0; z<src.depth; z++) 
        {
            for(unsigned int y=0; y<src.height; y++)
            {
                for(unsigned int x=0; x<src.width; x++)
                {
                    dstptr[x] = U::pixelConvert(srcptr[x]);
                }
                srcptr += src.rowPitch;
                dstptr += dst.rowPitch;
            }
            srcptr += srcSliceSkip;
            dstptr += dstSliceSkip;
        }    
    }
};

template <typename T, typename U, int id> struct PixelConverter {
    static const int ID = id;
    typedef T SrcType;
    typedef U DstType;    
    
    inline static DstType pixelConvert(SrcType inp);
};

struct A8R8G8B8toA8B8G8R8: public PixelConverter <uint32, uint32, FMTCONVERTERID(PF_A8R8G8B8, PF_A8B8G8R8)>
{
    inline static DstType pixelConvert(SrcType inp)
    {
        return (inp&0xFF00FF00)|((inp&0x00FF0000)>>16)|((inp&0x000000FF)<<16);
    }
};

struct A8B8G8R8toA8R8G8B8: public PixelConverter <uint32, uint32, FMTCONVERTERID(PF_A8B8G8R8, PF_A8R8G8B8)>
{
    inline static DstType pixelConvert(SrcType inp)
    {
        return (inp&0xFF00FF00)|((inp&0x00FF0000)>>16)|((inp&0x000000FF)<<16);
    }
};

struct B8G8R8A8toA8B8G8R8: public PixelConverter <uint32, uint32, FMTCONVERTERID(PF_B8G8R8A8, PF_A8B8G8R8)>
{
    inline static DstType pixelConvert(SrcType inp)
    {
        return ((inp&0x00FFFF00)>>8)|((inp&0xFF000000)>>8)|((inp&0x000000FF)<<24);
    }
};

struct A8B8G8R8toB8G8R8A8: public PixelConverter <uint32, uint32, FMTCONVERTERID(PF_A8B8G8R8, PF_B8G8R8A8)>
{
    inline static DstType pixelConvert(SrcType inp)
    {
        return ((inp&0x0000FFFF)<<8)|((inp&0x00FF0000)<<8)|((inp&0xFF000000)>>24);
    }
};

struct A8B8G8R8toL8: public PixelConverter <uint32, uint8, FMTCONVERTERID(PF_A8B8G8R8, PF_L8)>
{
    inline static DstType pixelConvert(SrcType inp)
    {
        return (uint8)(inp&0x000000FF);
    }
};

struct L8toA8B8G8R8: public PixelConverter <uint8, uint32, FMTCONVERTERID(PF_L8, PF_A8B8G8R8)>
{
    inline static DstType pixelConvert(SrcType inp)
    {
        return 0xFF000000|(((unsigned int)inp)<<0)|(((unsigned int)inp)<<8)|(((unsigned int)inp)<<16);
    }
};

struct A8R8G8B8toL8: public PixelConverter <uint32, uint8, FMTCONVERTERID(PF_A8R8G8B8, PF_L8)>
{
    inline static DstType pixelConvert(SrcType inp)
    {
        return (uint8)((inp&0x00FF0000)>>16);
    }
};

struct L8toA8R8G8B8: public PixelConverter <uint8, uint32, FMTCONVERTERID(PF_L8, PF_A8R8G8B8)>
{
    inline static DstType pixelConvert(SrcType inp)
    {
        return 0xFF000000|(((unsigned int)inp)<<0)|(((unsigned int)inp)<<8)|(((unsigned int)inp)<<16);
    }
};

struct B8G8R8A8toL8: public PixelConverter <uint32, uint8, FMTCONVERTERID(PF_B8G8R8A8, PF_L8)>
{
    inline static DstType pixelConvert(SrcType inp)
    {
        return (uint8)((inp&0x0000FF00)>>8);
    }
};

struct L8toB8G8R8A8: public PixelConverter <uint8, uint32, FMTCONVERTERID(PF_L8, PF_B8G8R8A8)>
{
    inline static DstType pixelConvert(SrcType inp)
    {
        return 0x000000FF|(((unsigned int)inp)<<8)|(((unsigned int)inp)<<16)|(((unsigned int)inp)<<24);
    }
};

struct L8toL16: public PixelConverter <uint8, uint16, FMTCONVERTERID(PF_L8, PF_L16)>
{
    inline static DstType pixelConvert(SrcType inp)
    {
        return (uint16)((((unsigned int)inp)<<8)|(((unsigned int)inp)));
    }
};

struct L16toL8: public PixelConverter <uint16, uint8, FMTCONVERTERID(PF_L16, PF_L8)>
{
    inline static DstType pixelConvert(SrcType inp)
    {
        return (uint8)(inp>>8);
    }
};

#define CASECONVERTER(type) case type::ID : PixelBoxConverter<type>::conversion(src, dst); return 1;

inline int doOptimizedConversion(const PixelBox &src, const PixelBox &dst)
{;
    switch(FMTCONVERTERID(src.format, dst.format))
    {
        // Register converters here
        CASECONVERTER(A8R8G8B8toA8B8G8R8);
        CASECONVERTER(A8B8G8R8toA8R8G8B8);
        CASECONVERTER(B8G8R8A8toA8B8G8R8);
        CASECONVERTER(A8B8G8R8toB8G8R8A8);
        CASECONVERTER(A8B8G8R8toL8);
        CASECONVERTER(L8toA8B8G8R8);
        CASECONVERTER(A8R8G8B8toL8);
        CASECONVERTER(L8toA8R8G8B8);
        CASECONVERTER(B8G8R8A8toL8);
        CASECONVERTER(L8toB8G8R8A8);
        CASECONVERTER(L8toL16);
        CASECONVERTER(L16toL8);
        default:
            return 0;
    }
}
#undef CASECONVERTER