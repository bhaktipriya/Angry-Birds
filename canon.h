  
class canon {
  public:

    VAO *rectangle, *point, *wheel;
    float drag, x, y;

    canon () {
      this->x = -13;
      this->y = groundLevel;
      this->drag = 0.01;

      // GL3 accepts onlytime Triangles. Quads are not supported
      GLfloat vertex_buffer_data [] = {
        -2,-0.2,0, // vertex 1
        2,-0.2,0, // vertex 2
        2, 0.2,0, // vertex 3

       2, 0.2,0, // vertex 3
       -2, 0.2,0, // vertex 4
        -2,-0.2,0// vertex 1
       
        
      };
      this->drag=drag;

      GLfloat color_buffer_data [] = {
        1,0,0, // color 1
        1,0,1, // color 2
        1,1,0, // color 3


        1,0,0,  // color 1
        1,1,0, // color 3
        0.3,0.3,0.3, // color 4
      };

     
      rectangle = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data, texture_buffer_data, textureID[0], GL_FILL);
      //rectangle = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data, GL_FILL);
      // GL3 accepts onlytime Triangles. Quads are not supported


      GLfloat vertex_buffer_data1 [] = {
        -0.05,-0.05,0, // vertex 1
        0.05,-0.05,0, // vertex 2
        0.05, 0.05,0, // vertex 3


        -0.05,-0.05,0, // vertex 1
        0.05, 0.05,0, // vertex 3
        -0.05, 0.05,0 // vertex 4
      };

      GLfloat color_buffer_data1 [] = {
        1,0,1, // color 1
        1,0,1, // color 2
        1,1,1, // color 3


        1,2,1,  // color 1
        1,1,1, // color 3
        0.3,0.3,0.3 // color 4
      };
      point = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data1, color_buffer_data1, GL_FILL);

      GLfloat vertex_buffer_data2 [] = {
        -0.5,-0.5,0, // vertex 1
        0.5,-0.5,0, // vertex 2
        0.5, 0.5,0, // vertex 3


        -0.5,-0.5,0, // vertex 1
        0.5, 0.5,0, // vertex 3
        -0.5, 0.5,0 // vertex 4
      };

      GLfloat color_buffer_data2 [] = {
        0,0,1, // color 1
        0,0,1, // color 2
        0,0,1, // color 3


        0,0,1,  // color 1
        0,0,1, // color 3
        0,0,1, // color 4
      };

      wheel = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data2, texture_buffer_data, textureID[0], GL_FILL);

    }

    void plotPath() {
        //this->x = -12;
      //this->y = groundLevel+2;
      float tx = -12,ty = groundLevel+2;
      float vx = boost*cos(rectangle_rotation*M_PI/180.0);
      float vy = boost*sin(rectangle_rotation*M_PI/180.0);
      int ct=0;
      glUseProgram(programID);
      while(tx <= zoom_scale && ty<=zoom_scale && tx>=-zoom_scale && ty>=-zoom_scale &&tx<=-2) {
        tx += vx*0.01 - 0.5*drag*0.0001;
        ty += vy*0.01 - 0.5*gravity*0.0001;
        vy -= gravity*0.01;
        vx -= drag*0.01;
        if(vx<=0) vx = 0; 
        // if(vy<=0) vy = 0; 
        glm::mat4 translateRectangle;


        glm::mat4 VP = Matrices.projection * Matrices.view;

        glm::mat4 MVP;  // MVP = Projection * View * Model
        Matrices.model = glm::mat4(1.0f);

        translateRectangle = glm::translate (glm::vec3(tx, ty, 0));        // glTranslatef

        Matrices.model *= (translateRectangle);
        MVP = VP * Matrices.model;
        glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);

        // draw3DObject draws the VAO given to it using current MVP matrix

        draw3DObject(point);
        ct++;
      }

      ct=0;

    }
    void draw ()
    {
      glUseProgram (textureProgramID);

      glm::mat4 translateRectangle;


      glm::mat4 VP = Matrices.projection * Matrices.view;

      // Send our transformation to the currently bound shader, in the "MVP" uniform
      // For each model you render, since the MVP will be different (at least the M part)
      //  Don't change unless you are sure!!
      glm::mat4 MVP;  // MVP = Projection * View * Model

      // Load identity to model matrix
      Matrices.model = glm::mat4(1.0f);

      translateRectangle = glm::translate (glm::vec3(x, y, 0));        // glTranslatef
      glm::mat4 rotateRectangle = glm::rotate((float)(rectangle_rotation*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,1,1)
      Matrices.model *= (translateRectangle * rotateRectangle);
      MVP = VP * Matrices.model;
      glUniformMatrix4fv(Matrices.TexMatrixID, 1, GL_FALSE, &MVP[0][0]);

      // Set the texture sampler to access Texture0 memory
      glUniform1i(glGetUniformLocation(textureProgramID, "texSampler"), 0);
draw3DTexturedObject(rectangle);
      // draw3DObject draws the VAO given to it using current MVP matrix

      Matrices.model = glm::mat4(1.0f);
      translateRectangle = glm::translate (glm::vec3(x-1+rectangle_rotation*0.009, y-0.5, 0));        // glTranslatef
      // glm::mat4 rotateRectangle = glm::rotate((float)(rectangle_rotation*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,1,1)
      Matrices.model *= (translateRectangle);
      MVP = VP * Matrices.model;
      // Copy MVP to texture shaders
      glUniformMatrix4fv(Matrices.TexMatrixID, 1, GL_FALSE, &MVP[0][0]);

      // Set the texture sampler to access Texture0 memory
      glUniform1i(glGetUniformLocation(textureProgramID, "texSampler"), 0);

      // draw3DObject draws the VAO given to it using current MVP matrix
            draw3DTexturedObject(wheel);
      plotPath();
      rectangle_rotation = rectangle_rotation + 1*rectangle_rot_dir*rectangle_rot_status;
      if(rectangle_rotation>120)
        rectangle_rotation=120;
      if(rectangle_rotation<0)
        rectangle_rotation=0;


      boost += (0.1*speed_inc);
      if(boost<4)
      boost=4;
      else if(boost>20)
      boost=20;

    }
};


