#ifndef ROCKETVIEWER_H
#define ROCKETVIEWER_H

#include "Triangle.h"
#include "Circle.h"
#include "Quad.h"
#include "Rocket.h"
#include "TriangleViewer.h"
#include "CircleViewer.h"
#include "QuadViewer.h"
#include <GL/glut.h>

/**
 * @brief A class responsible for drawing a Rocket using OpenGL
 */
class RocketViewer
{
    private:
        Rocket rocket_; ///< The Rocket to be drawn

    public:
        /**
         * @brief Default constructor for RocketViewer
         */
        RocketViewer(): rocket_(){}

        /**
         * @brief Draws the Rocket using OpenGL
         */
        void draw(){
          TriangleViewer coneView(rocket_.getCone());
          coneView.draw();
          QuadViewer bodyView(rocket_.getBody());
          bodyView.draw();
          QuadViewer nozzleViewer(rocket_.getNozzle());
          nozzleViewer.draw();
        }
        void moveRocket(float x, float y){
            this->rocket_.moveRocket(x, y);
        }
        Rocket getRocket(){
            return this->rocket_;
        }

    protected:

};

#endif // ROCKETVIEWER_H
