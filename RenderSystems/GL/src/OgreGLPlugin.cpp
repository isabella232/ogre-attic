/*
-----------------------------------------------------------------------------
This source file is part of OGRE
(Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2006 Torus Knot Software Ltd
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

You may alternatively use this source under the terms of a specific version of
the OGRE Unrestricted License provided you have obtained such a license from
Torus Knot Software Ltd.
-----------------------------------------------------------------------------
*/

#include "OgreGLPlugin.h"
#include "OgreRoot.h"

namespace Ogre 
{
	const String sPluginName = "GL RenderSystem";
	//---------------------------------------------------------------------
	GLPlugin::GLPlugin()
		: mRenderSystem(0), mGLSLProgramFactory(0)
	{

	}
	//---------------------------------------------------------------------
	const String& GLPlugin::getName() const
	{
		return sPluginName;
	}
	//---------------------------------------------------------------------
	void GLPlugin::install()
	{
		mRenderSystem = new GLRenderSystem();

		Root::getSingleton().addRenderSystem(mRenderSystem);

		mGLSLProgramFactory = new GLSLProgramFactory();
		HighLevelGpuProgramManager::getSingleton().addFactory(mGLSLProgramFactory);
	}
	//---------------------------------------------------------------------
	void GLPlugin::initialise()
	{
		// nothing to do
	}
	//---------------------------------------------------------------------
	void GLPlugin::shutdown()
	{
		// nothing to do
	}
	//---------------------------------------------------------------------
	void GLPlugin::uninstall()
	{
		delete mGLSLProgramFactory;
		mGLSLProgramFactory = 0;
		delete mRenderSystem;
		mRenderSystem = 0;

	}


}
