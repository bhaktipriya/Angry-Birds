#include "globals.h"
#include "block.h"
#include "bird.h"
#include "canon.h"
#include "speedy.h"

int main (int argc, char** argv)
{

int lives=3;

  int width = 1400;
  int height = 715;
  int numBlocks;

  points=10;
  /*float v[][6] = {
    2.5, -8.6, 3, 0.5,0,1,
    4, -7, 1, 4,0,1,
    5.5, -8.6, 3, 0.5,0,1,
    2.5, -5.5, 2, 1,1,1,
    4, -5.5, 2, 1,1,1,

    5.5, -5.5, 2, 1,1,1,
    4, -9.5, 2.5, 1.5, 2,2,
    4, -10.5, 1, 4, 0, 3,
    9, -9, 4, 4, 0, 3
  };*/


  GLFWwindow* window = initGLFW(width, height);

 initGL (window, width, height);
 float tm=glfwGetTime();
  elements e;
  while (glfwGetTime()-tm<=5 and mode==0)
  {
    e.menu();
    glfwSwapBuffers(window);
    glfwPollEvents();
  //  cout<<mode;  
  }

if(mode==0)
  mode=1;

if(mode==1){
  numBlocks= 12;
  groundLevel=-15;
}

dummy d1(0-2,12);

dummy d2(4-2,12);

dummy d3(8-2,12);
float v1[][6] = {
    2, -9.5-3, 3, 0.5,0,3,
    5, -9-3, 4, 0.5,0,3,

    8, -8.5-3, 5, 0.5,0,3,
    11, -8-3, 6, 0.5,0,3,
    
    2, -8-3, 1, 2,0,1,
    5, -7.0-3, 1, 2,0,1,
    
    8, -6.0-3, 1, 2,0,1,
    11, -5-3, 1, 2,0,1,
    
    2, -7-3, 1, 1,0,2,
    5, -6.0-3, 1, 1,0,2,
    
    8, -5.0, 1, 1,0,2,
    11, -4, 1, 1,0,2,
    
   // 2, -8+6, 1, 2,0,1,
    //5, -7+6, 1, 2,0,1,
    
   // 2,-8+9,1,1,0,2,
    //5, -7+9, 1, 1,0,2
};

if(mode==2)
{
  numBlocks=14;
  groundLevel=-15;
  
}


    float v2[][6] = {
    //0,-14.5,5,3,0,3,//hill
    //0,-11,1,1,1,4,//ball
    //7.5,groundLevel+4*2,1,5,0,1,
    2+4, -9.5-3, 3, 0.5,0,3,
    5+4, -9-3, 4, 0.5,0,3,
    8+4, -8.5-3, 5, 0.5,0,3,
    11+4, -8-3, 6, 0.5,0,3,
    
    2+4, -8-3, 1, 2,0,1,
    5+4, -7.0-3, 1, 2,0,1,
    
    8+4, -6.0-3, 1, 2,0,1,
    11+4, -5-3, 1, 2,0,1,

    2+4, -7-3, 1, 1,0,2,
    5+4, -6.0-3, 1, 1,0,2,
    
    2+4, -7-3, 1, 1,0,2,
    5+4, -6.0-3, 1, 1,0,2,
    
      
    8+4, -5.0, 1, 1,0,2,
    11+4, -4, 1, 1,0,2
   
};




 
  double last_update_time = glfwGetTime(), current_time;
  canon c;
  bird b(c.x-2, c.y-2);

  speedy speedo;
  vector<block> arr;

  for(int i=0; i<numBlocks;++i){
    if(mode==1){
    block a(v1[i][0], v1[i][1], v1[i][2], v1[i][3], v1[i][4], v1[i][5]);
   arr.push_back(a);
 }
    
    if(mode==2){
    block a(v2[i][0], v2[i][1], v2[i][2], v2[i][3], v2[i][4], v2[i][5]);
    arr.push_back(a);
  }

  }
  e.modeupdate();

  arr[1].fire(scale*2);
  while (!glfwWindowShouldClose(window) or glfwGetTime()-tm>=0.08 ) {

    // OpenGL Draw commands

  tm=glfwGetTime(); 


    e.draw();

    if(shoot == 1) {
      b.fire(boost, rectangle_rotation);
      shoot = 0;
    }

     c.draw();
     b.draw();
    

    for(int i=0; i<numBlocks;++i){
      bool flag=false;
     // if(i==1)
    //  cout<<i<<" "<<arr[i].vy<<" "<<arr[i].fall<<endl;
      for(int j=0; j<numBlocks;++j) {
        //if(i==1 and j==4)
        //cout<<arr[i].checkBelow(arr[j])<<" "<<;
        if(arr[i].checkBelow(arr[j])==true and i!=j){
          flag=true;
          
           //cout<<i<<" "<<j<<endl;

          //  if(arr[j].t==2 && arr[i].t==1) arr[j].lives--;
        }
        else if(arr[i].checkBelow(arr[j])==false and i!=j)
            {
                         }

      }
      if(flag==false)
        arr[i].fall=1;
      else arr[i].fall = 0,arr[i].vy=0;
      if(i==0)
        arr[i].fall = 0,arr[i].vy=0;
      arr[i].draw();
        

    }

    for(int i=4; i<numBlocks;++i) {
      for(int j=0; j<numBlocks;++j) {
        if(arr[i].checkCollision(arr[j]) && i!=j) {
         if(arr[j].type==1 && arr[i].type==4)
          arr[i].vx = arr[j].vx = (arr[i].vx+arr[j].vx)/2;

         if(arr[j].type==4&& arr[i].type==1)
          arr[i].vx = arr[j].vx = (arr[i].vx+arr[j].vx)/2;
          if(arr[j].type==1 && arr[i].type==1) {
          arr[i].vx = arr[j].vx = (arr[i].vx+arr[j].vx)/2;
         // arr[i].vy = arr[j].vy = (arr[i].vy+arr[j].vy)/2;
        }
   //     else if(arr[j].type == 3) {
          //cout<<"hi"<<endl;
    //      arr[i].vx = -coeff*arr[i].vx;
     // }
    }
    }
  }


    int hit,diff;

    for(int i=0; i<numBlocks;++i) {
      if(b.checkCollision(arr[i].x, arr[i].y, arr[i].h, arr[i].w, arr[i].alive))
      {
        if(arr[i].type == 2) {
          points+=10;
          arr[i].alive = false;
        }
        if(arr[i].type == 1 or arr[i].type==4) {
          arr[i].fire(scale*2);
        }
        if(arr[i].type==3)
          lives--;
        break;
      }
    }

    /*if(arr[i].t==2) {

      arr[i].lives=0;
      points+=arr[i].score;

      }*/
    /*  hit=arr[i].getLayer();
    //arr[i].fire(1);
    for(int j=0; j<numBlocks;++j){
    diff=(arr[j].getLayer()-hit);
    if(diff==0)
    arr[j].fire(scale*1.0);
    else if (diff==1) 
    arr[j].fire(scale*0.5);
    else if (diff==2) 
    arr[j].fire(scale*0.2);
    }
    break;  */
      //cout<<c.x<<" "<<c.y<<" "<<b.x<<" "<<b.y<<endl;  


    speedo.draw();

    if(lives==0)
      break;
    if(lives==1)
      d1.draw();
    if(lives==2){
      d1.draw();
      d2.draw();
    }
    if(lives==3){
    d1.draw();
    d2.draw();
    d3.draw();  
    }

    // Swap Frame Buffer in double buffering
    glfwSwapBuffers(window);

    // Poll for Keyboard and mouse events
    glfwPollEvents();

    // Control based on time (Time based transformation like 5 degrees rotation every 0.5s)
    current_time = glfwGetTime(); // Time in seconds
    if ((current_time - last_update_time) >= 0.5) { // atleast 0.5s elapsed since last frame
      // do something every 0.5 seconds ..
      last_update_time = current_time;
    }


  }
  cout<<"Score="<<points<<endl;;
    
  glfwTerminate();
  exit(EXIT_SUCCESS);
}
