from bitmap import Bitmap

"""

	z, t, c : TComplex;
	x, y, n : Integer;
	Cancel  : Boolean;
	gd, gm  : Smallint;
	mx, my  : Integer;
        col: TColor;
begin
   Randomize;
   PaintBox1.Canvas.Clear;
   Mx := PaintBox1.Canvas.Width div 2;
   My := PaintBox1.Canvas.Height div 2;
   	for y := -my to my do
		for x := -mx to mx do
		begin
			n := 0;
			z.x := x * 0.005;
			z.y := y * 0.005;
			c.x := 0.11;
			c.y := -0.66;
			while (sqr(z.x) + sqr(z.y) < max) and (n < iter) do
			begin
				t := z;
				{z^2 + c}
				z.x := sqr(t.x) - sqr(t.y) + c.x;
				z.y := 2*t.x*t.y + c.y;
				Inc(n);
   			end;
			if n < iter then begin
                          col := n*6 mod 255;
                          PaintBox1.Canvas.Pixels[mx+x,my+y]:=RGBToColor(col,0,0);
			end;"""
size = 511
b = Bitmap(size+1, size+1)

b.clear()
max = 60
iter = 100
c = complex(0.11, -0.66)
Mx = My = size // 2
for y in range(-My, My+1):
    for x in range(-Mx, Mx+1):
        n = 0
        z = complex(x * 0.009, y * 0.009)
        while (z.real ** 2 + z.imag ** 2) < max and n < iter:
            t = z
            z = complex(pow(t, 2) + c.real, 2*t + c.imag)
            n += 1
        if n < iter:
            col = n*30 % 255
            b.setPixel(Mx+x, My+y, (col, 0, 0))
b.write('file.bmp')