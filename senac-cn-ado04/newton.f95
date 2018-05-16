program NEWTON_METHOD
implicit none

! Declaração das variáveis

! Variável que irá armazenar o número de iterações
integer :: MAX_ITERS = 100

! Variável que irá armazenar o iterador
integer :: i;

! Caracter que irá armanzer o input recebido
character(len=10) :: temp

! Variável que irá o número ao qual se deseja calcular a raíz
real :: input

! Variável que irá armazernar a aproximação atual do resultado
real :: current_guess

! Implementação do programa

    ! Garanta que pelo menos um argumento foi passado para o programa
    if (iargc() /= 1) then
        stop
    end if

    ! Converte o valor recebido para real
    call getarg(1, temp)
    read(temp, '(f10.0)') input

    ! Calcula de acordo com o método de newton
    current_guess = input / 2
    do i = 0, MAX_ITERS
        current_guess = (current_guess + (input / current_guess)) / 2
    end do

    ! imprime o resultado no terminal
    print *, current_guess

end program NEWTON_METHOD