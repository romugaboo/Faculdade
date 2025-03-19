function setup() {
    createCanvas(800,600);
}  
function draw() {
    translate(width/2,height/2);
    rotate(-HALF_PI);
    background(200,50);
    let ang = TWO_PI / 100;
    let a = 10;
    let b = 90;
    noStroke();
    fill('#FF0000');
    arc(0,0,200,200,0,a*ang,PIE);
    let inicio = a*ang;
    fill('#0000FF');
    arc(0,0,200,200,inicio,b*ang+inicio,PIE);
}