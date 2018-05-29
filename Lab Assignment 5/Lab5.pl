/**
 * === Star Tricked Puzzle ===
 * Last week, four UFO enthusiasts made sightings of UFOs on different days.
 * The government stepped in and was able to give each person a different, plausible explanation of what he/she really saw.
 * Can you predict the day each person sighted a UFO as well as the object that it turned out to be?
 */

% Government predicts these objects were what they really saw
object(balloon).
object(clothesline).
object(frisbee).
object(water_tower).

% Each object was seen on a different day of the week
day(tuesday).
day(wednesday).
day(thursday).
day(friday).

earlier(tuesday, wednesday).
earlier(tuesday, thursday).
earlier(tuesday, friday).
earlier(wednesday, thursday).
earlier(wednesday, friday).
earlier(thursday, friday).

later(friday, thursday).
later(friday, wednesday).
later(friday, tuesday).
later(thursday, wednesday).
later(thursday, tuesday).
later(wednesday, tuesday).

solve :-
	object(BarradaObject), object(GortObject), object(KlatuObject), object(NiktoObject),
	all_different([BarradaObject, GortObject, KlatuObject, NiktoObject]),

	day(BarradaDay), day(GortDay), day(KlatuDay), day(NiktoDay),
	all_different([BarradaDay, GortDay, KlatuDay, NiktoDay]),

	Triples = [ [barrada, BarradaObject, BarradaDay],
				[gort, GortObject, GortDay],
				[klatu, KlatuObject, KlatuDay],
				[nikto, NiktoObject, NiktoDay] ],

	% 1. Mr. Klatu made his sighting at some point earlier in the week than the one who saw the balloon,
	% 	 but at some point later in the week than the one who spotted the frisbee (who isnt Ms. Gort).
	get_info(Triples, [_, balloon, BalloonDay]),
	get_info(Triples, [_, frisbee, FrisbeeDay]),
	earlier(KlatuDay, BalloonDay),
	later(KlatuDay, FrisbeeDay),
	\+ member([gort, frisbee, _], Triples),

	% 2. Fridays sighting was made by either Ms. Barrada or the one who saw a clothesline (or both).
	( member([barrada, _, friday], Triples);
	  member([_, clothesline, friday], Triples);
	  member([barrada, clothesline, friday], Triples) ),

	% 3. Mr. Nikto did not make his sighting on Tuesday.
	\+ member([nikto, _, tuesday], Triples),

	% 4. Mr. Klatu is not the one whose object turned out to be a water tower.
	\+ member([klatu, water_tower, _], Triples),

	tell(barrada, BarradaObject, BarradaDay),
	tell(gort, GortObject, GortDay),
	tell(klatu, KlatuObject, KlatuDay),
	tell(nikto, NiktoObject, NiktoDay).

	% Succeeds if all elements of the argument list are bound and different.
	% Fails if any elements are unbound or equal to some other element.
	all_different([H | T]) :- member(H, T), !, fail.
	all_different([_ | T]) :- all_different(T).
	all_different([_]).

	% Get info of a specified UFO sighting
	get_info([X|_], X).
	get_info([_|T], X) :- get_info(T, X).

	tell(X, Y, Z) :- write(X), write(' saw a '), write(Y), write(' on '), write(Z), nl.