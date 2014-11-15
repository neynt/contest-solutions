print((lambda a,b,c:'Error' if a+b+c != 180 else 'Equilateral' if a==b==c else 'Isosceles' if a==b or b==c or a==c else 'Scalene')(*map(int, [input(), input(), input()])))
