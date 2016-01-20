
class speedy {
  public:
    float x,y,h,w;
    VAO *rectangle,*rectangle2;
    speedy() {
      x=5;
      y=5;
      h=0.25;
      w=1;
      // GL3 accepts onlytime Triangles. Quads are not supported
      GLfloat vertex_buffer_data [] = {
        -w/2,-h/2,0, // vertex 1
        w/2,-h/2,0, // vertex 2
        w/2, h/2,0, // vertex 3


        -w/2,-h/2,0, // vertex 1
        w/2, h/2,0, // vertex 3
        -w/2, h/2,0 // vertex 4
      };

      GLfloat color_buffer_data [] = {
        1,0,0, // color 1
        1,0,0, // color 2
        1,0,0, // color 3


        1,0,0,  // color 1
        1,0,0, // color 3
        1,0,0, // color 4
      };

      GLfloat color_buffer_data2 [] = {
        0,1,0, // color 1
        0,1,0, // color 2
        0,1,0, // color 3


        0,1,0,  // color 1
        0,1,0, // color 3
        0,1,0, // color 4
      };

      rectangle = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data, GL_FILL);
      rectangle2 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color_buffer_data2, GL_FILL);

      // GL3 accepts onlytime Triangles. Quads are not supported

    }
    void draw () {
      glUseProgram (programID);

      float tempx=x;
      for(int i=4;i<=20;++i){
        tempx+=h;
        glm::mat4 translateRectangle;
        glm::mat4 VP = Matrices.projection * Matrices.view;

        glm::mat4 MVP;  // MVP = Projection * View * Model

        // Load identity to model matrix
        Matrices.model = glm::mat4(1.0f);

        translateRectangle = glm::translate (glm::vec3(tempx, y, 0));        // glTranslatef
        Matrices.model *= (translateRectangle );

        MVP = VP * Matrices.model;
        glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);


        // draw3DObject draws the VAO given to it using current MVP matrix
        if (i<=boost)
          draw3DObject(rectangle);
        else
          draw3DObject(rectangle2);

      }

    }
};


class elements {
  public:
    VAO *ground, *sky[150],*rectangle,*playdessert,*playwaterfall;
    char buffer [33];
    float w, h, x, y;
    float tm;
    int ct;

    elements() {
      x = 0;
      y = -12;
      h = 2;
      w = 20;
      ct=0;

      GLfloat vertex_buffer_data [] = {
        -100,-100,0, // vertex 1
        100,-100,0, // vertex 2
        100, 1,0, // vertex 3


        -100,-100,0, // vertex 1
        100, 1,0, // vertex 3
        -100, 1,0 // vertex 4
      };


      GLfloat vertex_buffer_data2 [] = {
        -20,-20,0, // vertex 1
        20,-20,0, // vertex 2
        20, 20,0, // vertex 3


        -20,-20,0, // vertex 1
        20, 20,0, // vertex 3
        -20, 20,0 // vertex 4
      };
      GLfloat color_buffer_data [] = {
        1,0,0, // color 1
        0,0,1, // color 2
        0,1,0, // color 3


        1,0,0,  // color 1
        0,1,0, // color 3
        0.3,0.3,0.3, // color 4
      };
      ground = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data, texture_buffer_data, textureID[2], GL_FILL);
      
      for(int i=0;i<45;++i)
      sky[i] = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data2, texture_buffer_data, textureID[27+i], GL_FILL);
      

      //for(int i=0;i<45;++i)
      //menu[i] = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data2, texture_buffer_data, textureID[27+i], GL_FILL);
      

      //sky = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data2, texture_buffer_data, textureID[8], GL_FILL);
      rectangle = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data2, texture_buffer_data, textureID[8], GL_FILL);
      ct=0;
 if(mode==0)
      w=4,h=2;
    static const GLfloat texture_buffer_data3 [] = {
  0,1, // TexCoord 1 - bot left
  1,1, // TexCoord 2 - bot right
  1,0, // TexCoord 3 - top right

  1,0, // TexCoord 3 - top right
  0,0, // TexCoord 4 - top left
  0,1  // TexCoord 1 - bot left
};
       GLfloat vertex_buffer_data3 [] = {
        -w/2,-h/2,0, // vertex 1
        w/2,-h/2,0, // vertex 2
        w/2, h/2,0, // vertex 3
        w/2, h/2,0, // vertex 3
        -w/2, h/2,0, // vertex 4
        -w/2,-h/2,0 // vertex 1

      };
      
  //playButtonCircle=create3DObject(GL_TRIANGLES,6,vertex_buffer_data3,color_buffer_data3,GL_FILL);
    playwaterfall = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data3, texture_buffer_data3, textureID[16], GL_FILL);
  
    playdessert = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data3, texture_buffer_data3, textureID[17], GL_FILL);
     
      tm=glfwGetTime();

    }

  
    void modeupdate(){
      GLfloat vertex_buffer_data2 [] = {
        -20,-20,0, // vertex 1
        20,-20,0, // vertex 2
        20, 20,0, // vertex 3


        -20,-20,0, // vertex 1
        20, 20,0, // vertex 3
        -20, 20,0 // vertex 4
      };
      ct=0;
      if(mode==1)
      {

      for(int i=0;i<8;++i)
      sky[i] = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data2, texture_buffer_data, textureID[8+i], GL_FILL);
      }
      if(mode==2)
      {for(int i=0;i<8;++i)
      sky[i] = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data2, texture_buffer_data, textureID[18+i], GL_FILL);
      }

      //sky = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data2, texture_buffer_data, textureID[8], GL_FILL);
      rectangle = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data2, texture_buffer_data, textureID[8], GL_FILL);
      
      
    }
    void draw ()
    {

       // clear the color and depth in the frame buffer
      glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      // use the loaded shader program
      // Don't change unless you know what you are doing
      glUseProgram (textureProgramID);

      // Eye - Location of camera. Don't change unless you are sure!!
      glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
      // Target - Where is the camera looking at.  Don't change unless you are sure!!
      glm::vec3 target (0, 0, 0);
      // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
      glm::vec3 up (0, 1, 0);

      // Compute Camera matrix (view)
      // Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
      //  Don't change unless you are sure!!
      Matrices.view = glm::lookAt(glm::vec3(panx,0,3), glm::vec3(panx,0,0), glm::vec3(0,1,0)); // Fixed camera for 2D (ortho) in XY plane

      glm::mat4 translateRectangle;


      glm::mat4 VP = Matrices.projection * Matrices.view;

      // Send our transformation to the currently bound shader, in the "MVP" uniform
      // For each model you render, since the MVP will be different (at least the M part)
      //  Don't change unless you are sure!!
      glm::mat4 MVP;  // MVP = Projection * View * Model

      Matrices.model = glm::mat4(1.0f);

      translateRectangle = glm::translate (glm::vec3(0, 0, 0));        // glTranslatef
      glm::mat4 rotateRectangle = glm::rotate((float)(180*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,1,1)
      Matrices.model *= (translateRectangle*rotateRectangle);
      MVP = VP * Matrices.model;
      glUniformMatrix4fv(Matrices.TexMatrixID, 1, GL_FALSE, &MVP[0][0]);
      glUniform1i(glGetUniformLocation(textureProgramID, "texSampler"), 0);
     
     if(mode!=0){
      assert(ct<8);
      //cout<<ct<<"\n";
      draw3DTexturedObject(sky[7-ct]);
      ct++;
      ct%=8;
    }
    
  }

 void menu()
    {

      
       // clear the color and depth in the frame buffer
      glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      // use the loaded shader program
      // Don't change unless you know what you are doing
      glUseProgram (textureProgramID);

      // Eye - Location of camera. Don't change unless you are sure!!
      glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
      // Target - Where is the camera looking at.  Don't change unless you are sure!!
      glm::vec3 target (0, 0, 0);
      // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
      glm::vec3 up (0, 1, 0);

      // Compute Camera matrix (view)
      // Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
      //  Don't change unless you are sure!!
      Matrices.view = glm::lookAt(glm::vec3(panx,0,3), glm::vec3(panx,0,0), glm::vec3(0,1,0)); // Fixed camera for 2D (ortho) in XY plane

      glm::mat4 translateRectangle;


      glm::mat4 VP = Matrices.projection * Matrices.view;

      // Send our transformation to the currently bound shader, in the "MVP" uniform
      // For each model you render, since the MVP will be different (at least the M part)
      //  Don't change unless you are sure!!
      glm::mat4 MVP;  // MVP = Projection * View * Model

      Matrices.model = glm::mat4(1.0f);

      translateRectangle = glm::translate (glm::vec3(0, 0, 0));        // glTranslatef
      glm::mat4 rotateRectangle = glm::rotate((float)(180*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,1,1)
      Matrices.model *= (translateRectangle*rotateRectangle);
      MVP = VP * Matrices.model;
      glUniformMatrix4fv(Matrices.TexMatrixID, 1, GL_FALSE, &MVP[0][0]);
      glUniform1i(glGetUniformLocation(textureProgramID, "texSampler"), 0);
      //cout<<ct<<endl;
      assert(ct<44);
      //cout<<ct<<"\n";
      draw3DTexturedObject(sky[43-ct]);
      ct++;
      ct%=44;

     

      // Send our transformation to the currently bound shader, in the "MVP" uniform
      // For each model you render, since the MVP will be different (at least the M part)
      //  Don't change unless you are sure!!
      Matrices.model = glm::mat4(1.0f);

      translateRectangle = glm::translate (glm::vec3(-5, -5, 0));        // glTranslatef
      rotateRectangle = glm::rotate((float)(0*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,1,1)
      Matrices.model *= (translateRectangle*rotateRectangle);
      MVP = VP * Matrices.model;
      glUniformMatrix4fv(Matrices.TexMatrixID, 1, GL_FALSE, &MVP[0][0]);
      glUniform1i(glGetUniformLocation(textureProgramID, "texSampler"), 0);
      draw3DTexturedObject(playwaterfall);

       Matrices.model = glm::mat4(1.0f);

      translateRectangle = glm::translate (glm::vec3(5, -5, 0));        // glTranslatef
      rotateRectangle = glm::rotate((float)(0*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,1,1)
      Matrices.model *= (translateRectangle*rotateRectangle);
      MVP = VP * Matrices.model;
      glUniformMatrix4fv(Matrices.TexMatrixID, 1, GL_FALSE, &MVP[0][0]);
      glUniform1i(glGetUniformLocation(textureProgramID, "texSampler"), 0);
      draw3DTexturedObject(playdessert);
    }



};

