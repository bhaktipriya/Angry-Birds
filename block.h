

class block {
  public:
    VAO *rectangle,*sink;
    float x,y,h,w, vx,vy, boost, theta,drag,radius;
    int update_theta, fall, type;
    int score, lives,fl;    
    bool alive;

    block(float x, float y, float h, float w, float col, int type) {
      this->x=x;
      this->y=y;
      this->h=h;
      this->w=w;
      this->type = type;
      this->drag = 5;
      this->update_theta = 0;
      //if(y-h/2<=groundLevel)
      this->fall = 0;
      this->theta = 0;
      alive = true;
      this->vx = 0;
      this->vy = 0;
      fl=0;

      GLfloat vertex_buffer_data [] = {
        -w/2,-h/2,0, // vertex 1
        w/2,-h/2,0, // vertex 2
        w/2, h/2,0, // vertex 3
w/2, h/2,0, // vertex 3
 -w/2, h/2,0, // vertex 4
        -w/2,-h/2,0 // vertex 1
        
       
      };


      GLfloat vertex_buffer_data2 [] = {
        -w/2,-h/4,0, // vertex 1
        w/2,-h/4,0, // vertex 2
        w/2, h/4,0, // vertex 3
w/2, h/4,0, // vertex 3
 -w/2, h/4,0, // vertex 4
        -w/2,-h/4,0 // vertex 1
        
       
      };
      GLfloat color_buffer_data [] = {
        0,col,1, // color 1
        0,col,1, // color 2
        0,col,1, // color 3


        0,col,1,  // color 1
        0,col,1, // color 3
        0,col,1, // color 4
      };

 static const GLfloat texture_buffer_data [] = {
  0,0, // TexCoord 3 - top right
  1,1, // TexCoord 4 - top left
  0,1,  // TexCoord 1 - bot left
  0,0, // TexCoord 1 - bot left
  1,0, // TexCoord 2 - bot right
  1,1, // TexCoord 3 - top right

  
};

static const GLfloat texture_buffer_data_tr [] = {
  0,0, // TexCoord 3 - top right
  1,1, // TexCoord 4 - top left
  0,1,  // TexCoord 1 - bot left
  0,0, // TexCoord 1 - bot left
  1,0, // TexCoord 2 - bot right
  1,1, // TexCoord 3 - top right
 
};

GLfloat* texture_buffer_data_cir=new GLfloat[2*360];

 GLfloat* vertex_buffer_data_cir = new GLfloat[3*360];
  GLfloat* color_buffer_data_cir = new GLfloat [3*360];

  for(int i=0; i<360; i++)
  {
    texture_buffer_data_cir[2*i]=cos((i)*M_PI/180.0)*0.5+0.5;
    texture_buffer_data_cir[2*i+1]=(sin((i)*M_PI/180.0)*0.5)+0.5;
    
    vertex_buffer_data_cir [3*i] = (w * cos((i)*M_PI/180.0));
    vertex_buffer_data_cir [3*i+1] = (h* sin((i)*M_PI/180.0));
    vertex_buffer_data_cir [3*i+2] = 0;

    color_buffer_data_cir [3*i] = 0;
    color_buffer_data_cir [3*i + 1] = 1;
    color_buffer_data_cir [3*i + 2] = 0;
  }
      if(type==3) 
        {

        //rectangle = create3DObject(GL_TRIANGLE_FAN, 360, vertex_buffer_data_cir, color_buffer_data_cir, GL_FILL);
        if(mode==2){
        rectangle = create3DTexturedObject(GL_TRIANGLE_FAN, 360, vertex_buffer_data_cir, texture_buffer_data_cir,textureID[26],GL_FILL);
        radius=3;
        h+=2;
        
        }
        if(mode==1)
          rectangle = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data, texture_buffer_data, textureID[5], GL_FILL);
        
        
          //rectangle = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data, texture_buffer_data, textureID[5], GL_FILL);
          //sink = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data2, texture_buffer_data, textureID[5], GL_FILL);
      
      }else if(type == 1){
        rectangle = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data, texture_buffer_data, textureID[6], GL_FILL);
       sink = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data2, texture_buffer_data, textureID[6], GL_FILL);
         
      }
      else if(type == 2){
         for(int i=0; i<360; i++)
      {
        texture_buffer_data_cir[2*i]=cos((i)*M_PI/180.0)*0.5+0.5;
        texture_buffer_data_cir[2*i+1]=(sin((i)*M_PI/180.0)*0.5)+0.5;
        
        vertex_buffer_data_cir [3*i] = (0.7 * cos((i)*M_PI/180.0));
        vertex_buffer_data_cir [3*i+1] = (1* sin((i)*M_PI/180.0));
        vertex_buffer_data_cir [3*i+2] = 0;

        color_buffer_data_cir [3*i] = 0;
        color_buffer_data_cir [3*i + 1] = 1;
        color_buffer_data_cir [3*i + 2] = 0;
  }
      rectangle = create3DTexturedObject(GL_TRIANGLE_FAN, 360, vertex_buffer_data_cir, texture_buffer_data_cir,textureID[7],GL_FILL);
        
      //rectangle = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data, texture_buffer_data, textureID[7], GL_FILL);
      sink = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data2, texture_buffer_data, textureID[7], GL_FILL);
     
      }
    else if(type == 4){
        rectangle = create3DObject(GL_TRIANGLE_FAN, 360, vertex_buffer_data_cir, color_buffer_data_cir, GL_FILL);
        radius=3;
        //rectangle = create3DTexturedObject(GL_TRIANGLES, 3, vertex_buffer_data_tr, texture_buffer_data_tr, textureID[7], GL_FILL);
     // sink = create3DTexturedObject(GL_TRIANGLES, 6, vertex_buffer_data2, texture_buffer_data, textureID[7], GL_FILL);
     
      }




      //rectangle 
    }
    void fire(float boost) {
      vx = boost*10;
    }
    bool checkBelow(block t2){

      float l1x=x-w/2,l1y=y+h/2,r1x=x+w/2,r1y=y-h/2;
      float l2x=t2.x-t2.w/2,l2y=t2.y+t2.h/2,r2x=t2.x+t2.w/2,r2y=t2.y-t2.h/2;
     /* if(type==2 and t2.type!=2){
        float tmpx, tmpy;
      for(int i=0; i<=360; i++) {
        tmpx = x+1*radius*cos(i*M_PI/180.0);
        tmpy = y+1*radius*sin(i*M_PI/180.0);

        if(tmpx>= l2x && tmpx<=r2x && tmpy>= r2y && tmpy <=l2y) {
         // if(tmpx>l2x && tmpx<r2x) vy=-coeff*vy;
          //cout<<vx<<" "<<vy<<endl;
          if(tmpy>= r2y) {
            //vx =-coeff*vx;
          //cout<<"y"<<endl;
          return true;
      

      }
    }
  }
}
if(type==2 and t2.type==2){
        float tmpx, tmpy,tmpx2,tmpy2;
      for(int i=0; i<=360; i++) {
        tmpx = x+1*radius*cos(i*M_PI/180.0);
        tmpy = y+1*radius*sin(i*M_PI/180.0);
      for(int j=0; j<=360; j++) {
      tmpx2 = t2.x+1*radius*cos(i*M_PI/180.0);
      tmpy2 = t2.y+1*radius*sin(i*M_PI/180.0);
      
      if(tmpx==tmpx2 and tmpy==tmpy2)
      return true;
      
      }
}
return false;
}*/
  

      

      if(l2y>=r1y and l2y<=y and l2x<=r1x and l2x>=x)
        return true;
      if(l2y>=r1y and l2y<=y and r2x>=l1x and r2x<=x) 
        return true;

      if(l2y>=r1y and l2y<=y and l2x<=x and r2x>=x) 
        return true;

      if(l2y>=r1y and l2y<=y and t2.x>=l1x and t2.x<=r1x) 
        return true;

      return false;   
      //if(t2.y+t2.h/2>=y-h/2 && (t2.x+t2.w/2>=x-w/2 || t2.x-t2.w/2<=x+w/2)) return true;
        //        else return false;
      //if((t2.x+t2.w/2<x-w/2 or t2.x-t2.w/2>x+w/2)) return false;
      //else if()  or (t2.y-t2.h/2>y+h/2 or t2.x-t2.w/2>x+w/2 or t2.y+t2.h/2<y-h/2 ) return false;
      //return true;
      //checks if t2 is below this block
      /*float l1x=x-w/2,l1y=y+h/2,r1x=x+w/2,r1y=y-h/2;
        float l2x=t3.x-w/2,l2y=t3.y+h/2,r2x=t3.x+w/2,r2y=t3.y-h/2;

        if(l2y<r1y and r2x>l1x)
        return false;
        return true;*/
  }
    bool checkCollision(block t3) {
      if(alive==false) return false;
      float l1x=x-w/2,l1y=y+h/2,r1x=x+w/2,r1y=y-h/2;
      float l2x=t3.x-t3.w/2,l2y=t3.y+t3.h/2,r2x=t3.x+t3.w/2,r2y=t3.y-t3.h/2;

      if(type==4)
      {
        //cout<<"he";
      float tmpx, tmpy;
      for(int i=0; i<=360; i++) {
        tmpx = x+1*radius*cos(i*M_PI/180.0);
        tmpy = y+1*radius*sin(i*M_PI/180.0);

        if(tmpx>= l2x && tmpx<=r2x && tmpy>= r2y && tmpy <=l2y) {
         // if(tmpx>l2x && tmpx<r2x) vy=-coeff*vy;
          //cout<<vx<<" "<<vy<<endl;
          if(tmpy>= r2y && tmpy <=l2y) {vx =-coeff*vx;
          //cout<<"y"<<endl;
          return true;
        }
        }
        return false;
      }
      }
      if(t3.type == 3 && l1y >= l2y) return false;
     
      if (l1x > r2x || l2x > r1x)
        return false;
      if (l1y < r2y || l2y < r1y)
        return false;
      return true;

    }

    void update() {
      if(type==3) return;
      //cout<<y<<" "<<fall<<endl;

      if(vx>0) {
        this->x += this->vx*0.01 - 0.5*drag*0.0001;
        this->vx -= drag*0.01;
      }
      //cout<<vx<< " "<<x<<endl;
      if(fall) {
        if(type==4)
          gravity+=5;
        this->y -= abs(this->vy)*0.01 + 0.5*gravity*0.0001;
        this->vy -= gravity*0.01;
        //cout<<y<<endl;

      
      if(type!=4 and y-h/2<=groundLevel+1 and h<w) {
       // fall = 0;
        vy = 0;
        y = groundLevel+1 +h/2;
      }
      if(type!=4 and y-w/2<=groundLevel+1 and h>=w)
      {
        y=groundLevel+w/2;

      }
      if(type==4 and y<=groundLevel+1){
        //cout<<"lol";
        fall = 0;
        vy = 0;
        y = groundLevel+1;
      }
    }
  }
    int getLayer(){
      if(y+h/2<=-7) 
        return 1;
      if(y+h/2<=-6) 
        return 2;
      if(y+h/2<=-5) 
        return 3;
    }

    void draw () {
      if(alive) {
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
        glm::mat4 rotateRectangle = glm::rotate((float)(theta*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,1,1)
        Matrices.model *= (translateRectangle * rotateRectangle);
        //Matrices.model *= (translateRectangle );

        MVP = VP * Matrices.model;
            glUniformMatrix4fv(Matrices.TexMatrixID, 1, GL_FALSE, &MVP[0][0]);
        if(type!=4)
            glUniform1i(glGetUniformLocation(textureProgramID, "texSampler"), 0);
            
    if(type==4)
    {
        glUseProgram (programID);
        Matrices.model = glm::mat4(1.0f);

        translateRectangle = glm::translate (glm::vec3(x, y, 0));        // glTranslatef
        glm::mat4 rotateRectangle = glm::rotate((float)(theta*M_PI/180.0f), glm::vec3(0,0,1)); // rotate about vector (-1,1,1)
        Matrices.model *= (translateRectangle * rotateRectangle);
        //Matrices.model *= (translateRectangle );

        MVP = VP * Matrices.model;
            glUniformMatrix4fv(Matrices.TexMatrixID, 1, GL_FALSE, &MVP[0][0]);
        
        draw3DObject(rectangle);
    }

    /*        if(mode==1){
           if(y>-11)
            draw3DTexturedObject(rectangle);
       else if(fl<=5)
        {draw3DTexturedObject(sink);fl++;}
    }*/

    else
    draw3DTexturedObject(rectangle);
     
        // draw3DObject draws the VAO given to it using current MVP matrix
      
     //   theta -= boost*update_theta;
     //   if(theta <= -90) update_theta = 0;

        update();
      }
    }
};



