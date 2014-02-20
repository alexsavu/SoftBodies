//
//  CustomNode.h
//  SoftBodyPhysics
//
//  Created by Alex Savu on 9/27/13.
//
//

#import "CCNode.h"
#import "Box2D.h"

// The number of outer circles (more, the smoother the circle)
#define NUM_SEGMENTS 20

typedef struct {
    GLfloat x;
    GLfloat y;
} Vertex2D;

static inline Vertex2D Vertex2DMake(GLfloat inX, GLfloat inY) {
    Vertex2D ret;
    ret.x = inX;
    ret.y = inY;
    return ret;
}


@interface CustomNode : CCNode
{
    // Texture
    CCTexture2D *texture;
    
    Vertex2D vertices[4];

    NSMutableArray *bodies;
    float deltaAngle;

    b2Body *innerCircleBody;
    Vertex2D triangleFanPos[NUM_SEGMENTS+2];
    
    // Texture coordinate array
    Vertex2D textCoords[NUM_SEGMENTS+2];
}

- (void) createPhysicsObject:(b2World*)world;
- (void) bounce;

@end
