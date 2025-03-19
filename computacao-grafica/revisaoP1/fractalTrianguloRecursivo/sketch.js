function setup() {
  createCanvas(400, 400);
  }
  
  function trianguloRecursivo(ax,ay,bx,by,cx,cy,n) {
  if(n == 0) {
  triangle(ax,ay,bx,by,cx,cy);
  } else {
  let mabx = (ax+bx)/2;
  let maby = (ay+by)/2;
  let mbcx = (cx+bx)/2;
  let mbcy = (cy+by)/2;
  let mcax = (cx+ax)/2;
  let mcay = (cy+ay)/2;
  trianguloRecursivo(ax,ay,mabx,maby,mcax,mcay,n-1);
  trianguloRecursivo(mabx,maby,bx,by,mbcx,mbcy,n-1);
  trianguloRecursivo(mcax,mcay,mbcx,mbcy,cx,cy,n-1);
  }
  
  }
  
  function draw() {
  background(220);
  noStroke();
  fill(0);
  trianguloRecursivo(20,380,380,380,200,20,4);
  }