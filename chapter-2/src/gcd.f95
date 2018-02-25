! -----------------------------------------------------------------------------
! FILE: 	gcd.f95
! AUTHOR: 	ANAS RCHID <rchid.anas@gmail.com>
! DESCRIPTION:	Ecluid's algorithm of gcd in fortran
!
! CREATION:	02/25/2018
! MODIFIED:	02/25/2018 
! -----------------------------------------------------------------------------

PROGRAM  GCD
  IMPLICIT  NONE
  INTEGER   :: n, m, tmp

  WRITE(*,*) 'TWO POSITIVE INTEGERS? '
  READ(*,*) n, m

  IF (n < m) THEN              ! swap input if it's in the wrong order
     tmp = n
     n = m
     m = tmp
  END IF

  DO
     tmp = MOD(n, m)            ! compute the remainder of n/m
     IF (tmp == 0) EXIT         ! break the loop if remainder is 0
     n = m                      ! n gets m
     m = tmp                    ! m gets the remainder 
  END DO

  WRITE(*,*) 'THE GCD IS ', m   ! output the result

END PROGRAM  GCD
