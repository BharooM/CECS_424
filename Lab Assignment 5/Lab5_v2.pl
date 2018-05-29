% lab assignment 5 - UFO sightings puzzle

% objects that were actually sighted
object('Balloon').
object('Clothesline').
object('Frisbee').
object('Water Tower').

% days of UFO sightings
day(1).
day(2).
day(3).
day(4).

solve :-
	object(BarradaObject), object(GortObject), object(KlatuObject), object(NiktoObject),
	all_different([BarradaObject, GortObject, KlatuObject, NiktoObject]),

	day(BarradaDay), day(GortDay), day(KlatuDay), day(NiktoDay),
	all_different([BarradaDay, GortDay, KlatuDay, NiktoDay]),

	Triples = [ ['Ms. Barrada', BarradaObject, BarradaDay],
				['Ms. Gort', GortObject, GortDay],
				['Mr. Klatu', KlatuObject, KlatuDay],
				['Mr. Nikto', NiktoObject, NiktoDay] ],

	% 1 - Mr. Klatu made his sighting at some point earlier in the week than the one who saw the balloon, but at some point later in the week than the one who spotted the frisbee (who isnt Ms. Gort).
	getter(Triples, [_, 'Balloon', BalloonDay]),
	getter(Triples, [_, 'Frisbee', FrisbeeDay]),
	before(KlatuDay, BalloonDay),
	after(KlatuDay, FrisbeeDay),
	\+ member(['Ms. Gort', 'Frisbee', _], Triples),

	% 2 - Fridays sighting was made by either Ms. Barrada or the one who saw a clothesline (or both).
	( member(['Ms. Barrada', _, 4], Triples);
	  member([_, 'Clothesline', 4], Triples);
	  member(['Ms. Barrada', 'Clothesline', 4], Triples) ),

	% 3 - Mr. Nikto did not make his sighting on Tuesday.
	\+ member(['Mr. Nikto', _, 1], Triples),

	% 4 - Mr. Klatu is not the one whose object turned out to be a water tower.
	\+ member(['Mr. Klatu', 'Water Tower', _], Triples),

	tell('Ms. Barrada', BarradaObject, BarradaDay),
	tell('Ms. Gort', GortObject, GortDay),
	tell('Mr. Klatu', KlatuObject, KlatuDay),
	tell('Mr. Nikto', NiktoObject, NiktoDay).

	% predicate functions for ordering the days
	before(X, Y) :- X < Y.
	after(X, Y) :- X > Y.

	% getter function for 'Triples' data structure
	getter([X|_], X).
	getter([_|T], X) :- getter(T, X).

	% Succeeds if all elements of the argument list are bound and different.
	% Fails if any elements are unbound or equal to some other element.
	all_different([H | T]) :- member(H, T), !, fail.
	all_different([_ | T]) :- all_different(T).
	all_different([_]).

	% output function
	tell(X, Y, Z) :- 
		write(X), 
		write(' sighted a '), 
		write(Y), 
		write(' on '), 
		( Z =:= 1 ->
        	write('Tuesday');
          Z =:= 2 ->
        	write('Wednesday');
          Z =:= 3 ->
        	write('Thursday');
          Z =:= 4 ->
        	write('Friday') )
		, nl.