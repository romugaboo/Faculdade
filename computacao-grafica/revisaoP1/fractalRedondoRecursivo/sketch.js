function setup() {
    createCanvas(640,360);  
  }
function draw() {
  background(255)
  desenha(width/2,height/2,400);
  noLoop()
}
function desenha(x, y, r) {
  stroke(0)
  noFill()
  ellipse(x, y, r, r)
  if(r > 2) {
    desenha(x + r/2, y, r/2)
    desenha(x - r/2, y, r/2)
  }
}