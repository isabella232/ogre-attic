/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.stevestreeting.com/ogre/

Copyright � 2000-2001 Steven J. Streeting
Also see acknowledgements in Readme.html

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/gpl.html.
-----------------------------------------------------------------------------
*/
#ifndef __Mesh_H__
#define __Mesh_H__

#include "OgrePrerequisites.h"

#include "OgreResource.h"
#include "OgreGeometryData.h"
#include "OgreAxisAlignedBox.h"

namespace Ogre {


    /** Resource holding data about 3D mesh.
        @remarks
            This class holds the data used to represent a discrete
            3-dimensional object. Mesh data usually contains more
            than just vertices and triangle information; it also
            includes references to materials (and the faces which use them),
            level-of-detail reduction information, convex hull definition,
            skeleton/bones information, keyframe animation etc.
            However, it is important to note the emphasis on the word
            'discrete' here. This class does not cover the large-scale
            sprawling geometry found in level / landscape data.
        @par
            Multiple world objects can (indeed should) be created from a
            single mesh object - see the Entity class for more info.
            The mesh object will have it's own default
            material properties, but potentially each world instance may
            wish to customise the materials from the original. When the object
            is instantiated into a scene node, the mesh material properties
            will be taken by default but may be changed. These properties
            are actually held at the SubMesh level since a single mesh may
            have parts with different materials.
        @par
            As described above, because the mesh may have sections of differing
            material properties, a mesh is inherently a compound contruct,
            consisting of one or more SubMesh objects.
            However, it strongly 'owns' it's SubMeshes such that they
            are loaded / unloaded at the same time. This is contrary to
            the approach taken to hierarchically related (but loosely owned)
            scene nodes, where data is loaded / unloaded separately. Note
            also that mesh sub-sections (when used in an instantiated object)
            share the same scene node as the parent.
    */



    class _OgreExport Mesh: public Resource
    {
    public:
        /** Default constructor - used by MeshManager
            @warning
                Do not call this method directly.
        */
        Mesh(String name);
        ~Mesh();

        /** Generic load - called by MeshManager.
        */
        virtual void load(void);

        /** Generic unload - called by MeshManager.
        */
        virtual void unload(void);

        // NB All methods below are non-virtual since they will be
        // called in the rendering loop - speed is of the essence.

        /** Creates a new SubMesh.
            @remarks
                Method for manually creating geometry for the mesh.
                Note - use with extreme caution - you must be sure that
                you have set up the geometry properly.
        */
        SubMesh* createSubMesh(void);

        /** Gets the number of sub meshes which comprise this mesh.
        */
        unsigned short getNumSubMeshes(void) const;

        /** Gets a pointer to the submesh indicated by the index.
        */
        SubMesh* getSubMesh(unsigned short index) const;

        /** Shared geometry data.
            @remarks
                This vertex data can be shared among multiple submeshes.
                When a submesh uses a very small subset of the shared geometry
                it is (processor) inefficient since the whole buffer is sent during the
                submesh rendering operation. Therefore in this case the SubMesh
                would use it's own vertex data. For other cases it is more
                memory efficient to use a shared buffer since vertices are not duplicated,
                or if hardware vertex buffers are available it can be better to
                use one set of data.
            @par
                The use of shared or non-shared buffers is determined when
                model data is converted to the OGRE Object Format - see the
                readme.txt in the 3ds2oof utility folder.
        */
        GeometryData sharedGeometry;

        /** Instructs the object to register all the Materials loaded with
            the SceneManager(s).
        */
        void _registerMaterials(void);

        /** Call this to indicate that this Mesh will be manually defined rather than loaded from a file.
            @remarks
                Normally, when load() is called on a Resource such as a Mesh, a file of data is loaded. However,
                by calling this method with a parameter of 'true' you are indicating that the contents of this
                Mesh will be defined programmatically rather than by loading from a file. Note that the load() method
                must still be called in order to confirm the Mesh's use for the renderer, set up materials etc.
        */
        void setManuallyDefined(bool manuallyDefined);

        /** Makes a copy of this mesh object and gives it a new name.
            @remarks
                This is useful if you want to tweak an existing mesh without affecting the original one. The
                newly cloned mesh is registered with the MeshManager under the new name.
        */
        Mesh* clone(String newName);

        /** Get the axis-aligned bounding box for this mesh.
        */
        const AxisAlignedBox& getBounds(void);

        /** Debugging method - dump contents to a readable text file.
        */
        void _dumpContents(String filename);
        void _dumpGeometry(GeometryData& g, std::ofstream& of);

        /** Updates the local bounding box of this mesh.
            @remarks
                Only needs to be called for manually modified meshes, loaded meshes do this automatically.
        */
        void _updateBounds(void);

        /** Manually set the bounding box for this Mesh.
            @remarks
                Use with care, designed only for internal engine usage. By calling this method
                you set the bounds of the mesh manually rather than letting the Mesh scan it's own
                geometry to derive it. This is most useful if you are building the Mesh geometry
                procedurally (e.g. see PatchSurface) and you have a simpler hull which you know it
                falls within.
        */
        void _setBounds(const AxisAlignedBox& bounds);

    private:
        typedef std::vector<SubMesh*> SubMeshList;
        /** A list of submeshes which make up this mesh.
            Each mesh is made up of 1 or more submeshes, which
            are each based on a single material and can have their
            own vertex data (they may not - they can share vertex data
            from the Mesh, depending on preference).
        */
        SubMeshList mSubMeshList;

        /// Local bounding box volume
        AxisAlignedBox mAABB;

        bool mManuallyDefined;

        /** Internal method used by clone().
        */
        void cloneGeometry(GeometryData& source, GeometryData& dest);

        /// Flag to indicate that bounds need updating
        bool mUpdateBounds;


    };


} // namespace

#endif
