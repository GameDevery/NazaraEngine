// Copyright (C) 2025 Jérôme "SirLynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - OpenGL renderer"
// For conditions of distribution and use, see copyright notice in Export.hpp

// no header guards

#ifndef NAZARA_DOCGEN

#if !defined(NAZARA_OPENGLRENDERER_FUNCTION)
#error You must define NAZARA_OPENGLRENDERER_FUNCTION before including this file
#endif

#ifndef NAZARA_OPENGLRENDERER_GL_FUNCTION
#define NAZARA_OPENGLRENDERER_GL_FUNCTION(ver, name, sig) NAZARA_OPENGLRENDERER_FUNCTION(name, sig)
#endif

#ifndef NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION
#define NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(glVer, glesVer, name, sig) NAZARA_OPENGLRENDERER_FUNCTION(name, sig)
#endif

// OpenGL core
NAZARA_OPENGLRENDERER_FUNCTION(glActiveTexture, PFNGLACTIVETEXTUREPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glAttachShader, PFNGLATTACHSHADERPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glBeginQuery, PFNGLBEGINQUERYPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glBindAttribLocation, PFNGLBINDATTRIBLOCATIONPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glBindBuffer, PFNGLBINDBUFFERPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glBindBufferRange, PFNGLBINDBUFFERRANGEPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glBindFramebuffer, PFNGLBINDFRAMEBUFFERPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glBindRenderbuffer, PFNGLBINDRENDERBUFFERPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glBindSampler, PFNGLBINDSAMPLERPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glBindTexture, PFNGLBINDTEXTUREPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glBindVertexArray, PFNGLBINDVERTEXARRAYPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glBlendEquationSeparate, PFNGLBLENDEQUATIONSEPARATEPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glBlendFuncSeparate, PFNGLBLENDFUNCSEPARATEPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glBlitFramebuffer, PFNGLBLITFRAMEBUFFERPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glBufferData, PFNGLBUFFERDATAPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glBufferSubData, PFNGLBUFFERSUBDATAPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glCheckFramebufferStatus, PFNGLCHECKFRAMEBUFFERSTATUSPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glClear, PFNGLCLEARPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glClearBufferfi, PFNGLCLEARBUFFERFIPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glClearBufferfv, PFNGLCLEARBUFFERFVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glClearBufferuiv, PFNGLCLEARBUFFERUIVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glClearColor, PFNGLCLEARCOLORPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glClearDepthf, PFNGLCLEARDEPTHFPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glClearStencil, PFNGLCLEARSTENCILPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glColorMask, PFNGLCOLORMASKPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glCompileShader, PFNGLCOMPILESHADERPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glCompressedTexSubImage2D, PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glCompressedTexSubImage3D, PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glCopyBufferSubData, PFNGLCOPYBUFFERSUBDATAPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glCopyTexSubImage2D, PFNGLCOPYTEXSUBIMAGE2DPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glCreateProgram, PFNGLCREATEPROGRAMPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glCreateShader, PFNGLCREATESHADERPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glCullFace, PFNGLCULLFACEPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDebugMessageInsert, PFNGLDEBUGMESSAGEINSERTPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDeleteBuffers, PFNGLDELETEBUFFERSPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDeleteFramebuffers, PFNGLDELETEFRAMEBUFFERSPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDeleteProgram, PFNGLDELETEPROGRAMPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDeleteQueries, PFNGLDELETEQUERIESPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDeleteRenderbuffers, PFNGLDELETERENDERBUFFERSPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDeleteSamplers, PFNGLDELETESAMPLERSPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDeleteShader, PFNGLDELETESHADERPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDeleteTextures, PFNGLDELETETEXTURESPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDeleteVertexArrays, PFNGLDELETEVERTEXARRAYSPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDepthFunc, PFNGLDEPTHFUNCPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDepthMask, PFNGLDEPTHMASKPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDisable, PFNGLDISABLEPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDisableVertexAttribArray, PFNGLDISABLEVERTEXATTRIBARRAYPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDrawArrays, PFNGLDRAWARRAYSPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDrawArraysInstanced, PFNGLDRAWARRAYSINSTANCEDPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDrawBuffers, PFNGLDRAWBUFFERSPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDrawElements, PFNGLDRAWELEMENTSPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glDrawElementsInstanced, PFNGLDRAWELEMENTSINSTANCEDPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glEnable, PFNGLENABLEPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glEnableVertexAttribArray, PFNGLENABLEVERTEXATTRIBARRAYPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glEndQuery, PFNGLENDQUERYPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glFinish, PFNGLFINISHPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glFlush, PFNGLFLUSHPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glFramebufferRenderbuffer, PFNGLFRAMEBUFFERRENDERBUFFERPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glFramebufferTexture2D, PFNGLFRAMEBUFFERTEXTURE2DPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glFramebufferTextureLayer, PFNGLFRAMEBUFFERTEXTURELAYERPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glFrontFace, PFNGLFRONTFACEPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGenBuffers, PFNGLGENBUFFERSPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGenFramebuffers, PFNGLGENFRAMEBUFFERSPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGenQueries, PFNGLGENQUERIESPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGenRenderbuffers, PFNGLGENRENDERBUFFERSPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGenSamplers, PFNGLGENSAMPLERSPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGenTextures, PFNGLGENTEXTURESPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGenVertexArrays, PFNGLGENVERTEXARRAYSPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGenerateMipmap, PFNGLGENERATEMIPMAPPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetActiveUniform, PFNGLGETACTIVEUNIFORMPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetActiveUniformsiv, PFNGLGETACTIVEUNIFORMSIVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetActiveUniformBlockiv, PFNGLGETACTIVEUNIFORMBLOCKIVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetActiveUniformBlockName, PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetBooleanv, PFNGLGETBOOLEANVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetBufferParameteriv, PFNGLGETBUFFERPARAMETERIVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetError, PFNGLGETERRORPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetFloatv, PFNGLGETFLOATVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetInteger64i_v, PFNGLGETINTEGER64I_VPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetInteger64v, PFNGLGETINTEGER64VPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetIntegeri_v, PFNGLGETINTEGERI_VPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetIntegerv, PFNGLGETINTEGERVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetProgramBinary, PFNGLGETPROGRAMBINARYPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetProgramInfoLog, PFNGLGETPROGRAMINFOLOGPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetProgramiv, PFNGLGETPROGRAMIVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetQueryObjectuiv, PFNGLGETQUERYOBJECTUIVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetQueryiv, PFNGLGETQUERYIVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetShaderInfoLog, PFNGLGETSHADERINFOLOGPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetShaderSource, PFNGLGETSHADERSOURCEPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetShaderiv, PFNGLGETSHADERIVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetString, PFNGLGETSTRINGPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetStringi, PFNGLGETSTRINGIPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetTexParameterfv, PFNGLGETTEXPARAMETERFVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetTexParameteriv, PFNGLGETTEXPARAMETERIVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetUniformLocation, PFNGLGETUNIFORMLOCATIONPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetUniformfv, PFNGLGETUNIFORMFVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetUniformiv, PFNGLGETUNIFORMIVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glGetUniformBlockIndex, PFNGLGETUNIFORMBLOCKINDEXPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glIsEnabled, PFNGLISENABLEDPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glInvalidateFramebuffer, PFNGLINVALIDATEFRAMEBUFFERPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glLineWidth, PFNGLLINEWIDTHPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glLinkProgram, PFNGLLINKPROGRAMPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glMapBufferRange, PFNGLMAPBUFFERRANGEPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glPixelStorei, PFNGLPIXELSTOREIPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glPolygonOffset, PFNGLPOLYGONOFFSETPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glProgramBinary, PFNGLPROGRAMBINARYPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glProgramParameteri, PFNGLPROGRAMPARAMETERIPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glReadPixels, PFNGLREADPIXELSPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glRenderbufferStorage, PFNGLRENDERBUFFERSTORAGEPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glSamplerParameterf, PFNGLSAMPLERPARAMETERFPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glSamplerParameterfv, PFNGLSAMPLERPARAMETERFVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glSamplerParameteri, PFNGLSAMPLERPARAMETERIPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glSamplerParameteriv, PFNGLSAMPLERPARAMETERIVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glScissor, PFNGLSCISSORPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glShaderBinary, PFNGLSHADERBINARYPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glShaderSource, PFNGLSHADERSOURCEPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glStencilFunc, PFNGLSTENCILFUNCPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glStencilFuncSeparate, PFNGLSTENCILFUNCSEPARATEPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glStencilOp, PFNGLSTENCILOPPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glStencilOpSeparate, PFNGLSTENCILOPSEPARATEPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glStencilMaskSeparate, PFNGLSTENCILMASKSEPARATEPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glTexImage2D, PFNGLTEXIMAGE2DPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glTexImage3D, PFNGLTEXIMAGE3DPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glTexParameterf, PFNGLTEXPARAMETERFPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glTexParameterfv, PFNGLTEXPARAMETERFVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glTexParameteri, PFNGLTEXPARAMETERIPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glTexParameteriv, PFNGLTEXPARAMETERIVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glTexStorage2D, PFNGLTEXSTORAGE2DPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glTexStorage3D, PFNGLTEXSTORAGE3DPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glTexSubImage2D, PFNGLTEXSUBIMAGE2DPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glTexSubImage3D, PFNGLTEXSUBIMAGE3DPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glUniform1f, PFNGLUNIFORM1FPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glUniform1fv, PFNGLUNIFORM1FVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glUniform1i, PFNGLUNIFORM1IPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glUniform1iv, PFNGLUNIFORM1IVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glUniform2fv, PFNGLUNIFORM2FVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glUniform2iv, PFNGLUNIFORM2IVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glUniform3fv, PFNGLUNIFORM3FVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glUniform3iv, PFNGLUNIFORM3IVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glUniform4fv, PFNGLUNIFORM4FVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glUniform4iv, PFNGLUNIFORM4IVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glUniformBlockBinding, PFNGLUNIFORMBLOCKBINDINGPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glUniformMatrix4fv, PFNGLUNIFORMMATRIX4FVPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glUnmapBuffer, PFNGLUNMAPBUFFERPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glUseProgram, PFNGLUSEPROGRAMPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glValidateProgram, PFNGLVALIDATEPROGRAMPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glVertexAttrib4f, PFNGLVERTEXATTRIB4FPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glVertexAttribDivisor, PFNGLVERTEXATTRIBDIVISORPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glVertexAttribIPointer, PFNGLVERTEXATTRIBIPOINTERPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glVertexAttribPointer, PFNGLVERTEXATTRIBPOINTERPROC)
NAZARA_OPENGLRENDERER_FUNCTION(glViewport, PFNGLVIEWPORTPROC)

// Core OpenGL (extension in OpenGL ES)
NAZARA_OPENGLRENDERER_GL_FUNCTION(100, glDebugMessageControl, PFNGLDEBUGMESSAGECONTROLPROC)
NAZARA_OPENGLRENDERER_GL_FUNCTION(100, glDrawBuffer, PFNGLDRAWBUFFERPROC) 
NAZARA_OPENGLRENDERER_GL_FUNCTION(100, glPolygonMode, PFNGLPOLYGONMODEPROC)

// OpenGL 3.2 - OpenGL ES 3.2
NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(320, 320, glDrawElementsInstancedBaseVertex, PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)

// OpenGL 4.2 - OpenGL ES 3.1
NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(420, 310, glBindImageTexture, PFNGLBINDIMAGETEXTUREPROC)
NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(420, 310, glGetBooleani_v, PFNGLGETBOOLEANI_VPROC)
NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(420, 310, glMemoryBarrier, PFNGLMEMORYBARRIERPROC)
NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(420, 310, glMemoryBarrierByRegion, PFNGLMEMORYBARRIERBYREGIONPROC)

// OpenGL 4.3 - OpenGL ES 3.1
NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(430, 310, glDispatchCompute, PFNGLDISPATCHCOMPUTEPROC)
NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(430, 310, glGetProgramInterfaceiv, PFNGLGETPROGRAMINTERFACEIVPROC)
NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(430, 310, glGetProgramResourceiv, PFNGLGETPROGRAMRESOURCEIVPROC)
NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(430, 310, glGetProgramResourceIndex, PFNGLGETPROGRAMRESOURCEINDEXPROC)
NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(430, 310, glGetProgramResourceLocation, PFNGLGETPROGRAMRESOURCELOCATIONPROC)
NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(430, 310, glGetProgramResourceName, PFNGLGETPROGRAMRESOURCENAMEPROC)

// OpenGL 4.3 - OpenGL ES 3.2
NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(430, 320, glCopyImageSubData, PFNGLCOPYIMAGESUBDATAPROC)
NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(430, 320, glDebugMessageCallback, PFNGLDEBUGMESSAGECALLBACKPROC)
NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(430, 320, glObjectLabel, PFNGLOBJECTLABELPROC)
NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(430, 320, glPopDebugGroup, PFNGLPOPDEBUGGROUPPROC)
NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION(430, 320, glPushDebugGroup, PFNGLPUSHDEBUGGROUPPROC)

// OpenGL 4.3 - GL_ARB_texture_view
NAZARA_OPENGLRENDERER_GL_FUNCTION(430, glTextureView, PFNGLTEXTUREVIEWPROC)

// OpenGL 4.5 - GL_ARB_clip_control/GL_EXT_clip_control
NAZARA_OPENGLRENDERER_GL_FUNCTION(450, glClipControl, PFNGLCLIPCONTROLPROC)

// OpenGL 4.6 - GL_ARB_spirv_extensions
NAZARA_OPENGLRENDERER_GL_FUNCTION(460, glSpecializeShader, PFNGLSPECIALIZESHADERPROC)

#undef NAZARA_OPENGLRENDERER_FUNCTION
#undef NAZARA_OPENGLRENDERER_FUNCTION_LAST
#undef NAZARA_OPENGLRENDERER_GL_FUNCTION
#undef NAZARA_OPENGLRENDERER_GL_GLES_FUNCTION

#endif // NAZARA_DOCGEN
