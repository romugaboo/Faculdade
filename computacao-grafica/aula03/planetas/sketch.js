
function setup() {
    createCanvas(800,600);
    rectMode(CENTER);
}  

function terra(){
    push();
    rotate(frameCount*0.02);
    translate(width/3,0);
    fill("blue");
    circle(0,0,60);

    rotate(frameCount*0.08);
    translate(width/12,0);
    fill("grey");
    circle(0,0,20);
    pop();
}

function mercurio(){
    push();
    rotate(frameCount*0.01);
    translate(width/6,0);
    fill("red");
    circle(0,0,20);
    pop();
}

function sistemaSolar(){
    push();
    fill("yellow");
    circle(0,0,100);
    mercurio();
    terra();
    pop();
}

function draw() {
    background(200);

    push();
    translate(width/4,height/4); 
    sistemaSolar();
    pop();
    //resetMatrix();

    push();
    translate(3*width/4,height/4); 
    sistemaSolar();
    pop();

    push();
    translate(width/4,3*height/4); 
    sistemaSolar();
    pop();

    push();
    translate(3*width/4,3*height/4); 
    sistemaSolar();
    pop();
}