/*===============================================================================
Copyright (c) 2016 PTC Inc. All Rights Reserved.

Copyright (c) 2012-2015 Qualcomm Connected Experiences, Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other 
countries.
===============================================================================*/

#import <UIKit/UIKit.h>

#import <Vuforia/UIGLViewProtocol.h>

#import "Texture.h"
#import "SampleApplicationSession.h"
#import "SampleApplication3DModel.h"
#import "SampleGLResourceHandler.h"
#import "SampleAppRenderer.h"

#define kNumAugmentationTextures 4


// EAGLView is a subclass of UIView and conforms to the informal protocol
// UIGLViewProtocol
@interface ImageTargetsEAGLView : UIView <UIGLViewProtocol, SampleGLResourceHandler, SampleAppRendererControl> {
@private
    // OpenGL ES context
    EAGLContext *context;
    
    // The OpenGL ES names for the framebuffer and renderbuffers used to render
    // to this view
    GLuint defaultFramebuffer;
    GLuint colorRenderbuffer;
    GLuint depthRenderbuffer;

    // Shader handles
    GLuint shaderProgramID;
    GLint vertexHandle;
    GLint normalHandle;
    GLint textureCoordHandle;
    GLint mvpMatrixHandle;
    GLint texSampler2DHandle;
    
    // Texture used when rendering augmentation
    Texture* augmentationTexture[kNumAugmentationTextures];
    
    BOOL offTargetTrackingEnabled;
    SampleApplication3DModel * buildingModel;
    
    SampleAppRenderer * sampleAppRenderer;
}

@property (nonatomic, weak) SampleApplicationSession * vapp;

- (id)initWithFrame:(CGRect)frame appSession:(SampleApplicationSession *) app;

- (void)finishOpenGLESCommands;
- (void)freeOpenGLESResources;

- (void) setOffTargetTrackingMode:(BOOL) enabled;

@end
