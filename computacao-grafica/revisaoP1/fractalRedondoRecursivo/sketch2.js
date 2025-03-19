function setup() {
    createCanvas(800,600)
}  
function draw() {
    background(255)
    desenha(width/2,height/2,200)
}
function desenha(x, y, r) {
    noFill()
    ellipse(x, y, r, r)
    if(r > 10) {
      desenha(x - r/2, y, r/2)
      desenha(x + r/2, y, r/2)
    }
}