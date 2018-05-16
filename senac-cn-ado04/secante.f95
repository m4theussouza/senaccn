program SECANT_METHODs
implicit none

! ######################################################################################
! # Declaração das variáveis
! ######################################################################################

! Variável que irá armazenar o número de iterações
integer :: MAX_ITERS = 100

! Variável que irá armazenar o iterador
integer :: i;

! Caracter que irá armanzer o input recebido
character(len=10) :: temp

! Variável que irá o número ao qual se deseja calcular a raíz
real :: input

! Variável que armazena o intervalo 
real :: a
real :: b
real :: c

! ######################################################################################
! # Implementação do programa
! ######################################################################################

    ! Garanta que pelo menos um argumento foi passado para o programa
    if (iargc() /= 1) then
        stop
    end if

    ! Converte o valor recebido para real
    call getarg(1, temp)
    read(temp, '(f10.0)') input

    ! Calcula de acordo com o método da secante
    a = 0
    b = input + 1
    c = 0

    do i = 0, MAX_ITERS
        if (b /= a) then
            c = b - (((b * b) - input) * ((b-a)) / (((b*b) - input) - ((a*a) - input)))
        end if
        a = b
        b = c        
    end do

    ! imprime o resultado no terminal
    print *, c

end program SECANT_METHODs