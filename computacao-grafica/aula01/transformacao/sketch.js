
function setup() {
    createCanvas(800,600);
    rectMode(CENTER);
}  

function draw() {
    background(200);
    //applyMatrix(1,0,0,1,width/2,height/2);
    translate(width/2,height/2);    
    //rotate(HALF_PI/2);
    rotate(frameCount*0.01);
    rect(0,0,100,100);
}