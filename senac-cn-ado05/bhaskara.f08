program bhaskara

implicit none
!variaveis
character(len=32) :: arg 
real :: a, b, c
real :: x1, x2
real :: delta

!coletando argumento de comando
call getarg(1, arg)
read(arg, *)a

call getarg(2, arg)
read(arg, *)b

call getarg(3, arg)
read(arg, *)c

!calculo do delta
delta = (b**2) - (4*a*c);

!se delta < 0 (complexos), multiplique por menos ache a parte real e a imaginaria
!e dps exibe os valores
if(delta < 0) then
   delta = delta * (-1)
   print ' ( "r1 = ", (f5.1), " i1 = ", (f5.1) ) ', ( -b / (2*a) ), ( +sqrt(delta) / (2*a) ) 
   print ' ( "r1 = ", (f5.1), " i1 = ", (f5.1) ) ', ( -b / (2*a) ), ( -sqrt(delta) / (2*a) )
else !se nao calule as raizes reais e mostre os valores
   x1 = ( -b + sqrt(delta) ) / (2 * a)
   x2 = ( -b - sqrt(delta) ) / (2 * a)
   print ' ( "r1 = ", (f5.1) ) ', x1
   print ' ( "r2 = ", (f5.1) ) ', x2
end if

end program bhaskara
