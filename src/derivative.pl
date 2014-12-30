% +Function +Variable -Derivative
derivative(X, X, 1) :-
	!.
derivative(C, X, 0) :-
	C \= X,
	atomic(C).
derivative(U+V, X, R) :-
	derivative(U, X, A),
	derivative(V, X, B),
	simplify_addition(A, B, R).
derivative(U-V, X, R) :-
	derivative(U, X, A),
	derivative(V, X, B),
	simplify_subtraction(A, B, R).
derivative(C*U, X, R) :-
	atomic(C),
	C \= X,
	derivative(U, X, A),
	simplify_multiplication(C, A, R),
	!.
derivative(C*U, X, R) :-
	atomic(U),
	U \= X,
	derivative(C, X, A),
	simplify_multiplication(U, A, R),
	!.
derivative(U*V, X, R):-
	derivative(U, X, A),
	derivative(V, X, B),
	simplify_multiplication(U, B, C),
	simplify_multiplication(V, A, D),
	simplify_addition(C, D, R).
derivative(U/V, X, R):-
	derivative(U, X, A),
	derivative(V, X, B),
	simplify_multiplication(A, V, A1),
	simplify_multiplication(B, U, B1),
	simplify_subtraction(A1, B1, C),
	simplify_division(C, V^2, R).
derivative(U^C, X, R) :-
	C \= X,
	atomic(C),
	derivative(U, X, A),
	simplify_multiplication(C, A, A1),
	simplify_subtraction(C, 1, C1),
	simplify_power(U, C1, U1),
	simplify_multiplication(A1, U1, R),
	!.
derivative(U^C, X, R) :-
	derivative(exp(C*log(U)), X, R).
derivative(exp(W), X, R):-
	derivative(W, X, Z),
	simplify_exponent(W, W1),
	simplify_multiplication(Z, W1, R).
derivative(log(W), X, R):-
	derivative(W, X, Z),
	simplify_division(Z, W, R).
derivative(sin(W), X, R) :-
	derivative(W, X, Z),
	simplify_multiplication(cos(W), Z, R).
derivative(cos(W), X, R):-
	derivative(W, X, Z),
	simplify_multiplication(sin(W), Z, K),
	simplify_multiplication(-1, K, R).
derivative(tg(W), X, R):-
	derivative(W, X, Z),
	simplify_division(Z, (cos(W))^2, R).
derivative(ctg(W), X, R):-
	derivative(W, X, Z),
	simplify_multiplication(-1, Z, Z1),
	simplify_division(Z1, (sin(W))^2, R).
derivative(arcsin(W), X, R):-
	derivative(W, X, Z),
	simplify_division(Z, (1-W^2)^0.5, R).
derivative(arccos(W), X, R):-
	derivative(W, X, Z),
	simplify_multiplication(-1, Z, Z1),
	simplify_division(Z1, (1-W^2)^0.5, R).
derivative(arctg(W), X, R):-
	derivative(W, X, Z),
	simplify_division(Z, 1+W^2, R).
derivative(arcctg(W), X, R):-
	derivative(W, X, Z),
	simplify_multiplication(-1, Z, Z1),
	simplify_division(Z1, 1+W^2, R).

% +A 1st operand +B 2nd operand -Result = A*B
simplify_multiplication(_, 0, 0) :- !.
simplify_multiplication(0, _, 0) :- !.
simplify_multiplication(1, C, C) :- !.
simplify_multiplication(C, 1, C) :- !.
simplify_multiplication(-1, C, -C) :- !.
simplify_multiplication(C, -1, -C) :- !.
simplify_multiplication(C, A, R) :-
	number(C),
	number(A),
	R is C * A, !.
simplify_multiplication(C, A, C*A).

% +A 1st operand +B 2nd operand -Result = A/B
simplify_division(_, 0, _) :- !, fail.
simplify_division(0, _, 0) :- !.
simplify_division(A, B, R) :-
	number(A),
	number(B),
	R is A / B, !.
simplify_division(A, B, A / B).

% +A 1st operand +B 2nd operand -Result = A+B
simplify_addition(C, 0, C) :- !.
simplify_addition(0, C, C) :- !.
simplify_addition(A, B, R) :-
	number(A),
	number(B),
	R is A + B, !.
simplify_addition(A, B, A+B).

% +A 1st operand +B 2nd operand -Result = A-B
simplify_subtraction(C, 0, C) :- !.
simplify_subtraction(0, C, C) :- !.
simplify_subtraction(A, B, R) :-
	number(A),
	number(B),
	R is A - B, !.
simplify_subtraction(A, B, A-B).

% +A 1st operand +B 2nd operand -Result = A^B
simplify_power(0, 0, _) :- !, fail.
simplify_power(0, B, 0) :- B \= 0, !.
simplify_power(A, 0, 1) :- A \= 0, !.
simplify_power(A, 1, A) :- !.
simplify_power(1, _, 1) :- !.
simplify_power(A, B, R) :-
	number(A),
	number(B),
	R is A^B, !.
simplify_power(A, B, A^B).

% +A 1st operand +B 2nd operand -Result = e^(A*log(B)) = B^A
simplify_exponent(A*log(B), B^A) :- !.
simplify_exponent(A, exp(A)).
