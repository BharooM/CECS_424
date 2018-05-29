-- 'qsort' uses Quicksort algorithm to sort values of any type
qsort :: Ord a => [a] -> [a]
qsort [] = []
qsort (x:xs) = qsort[y | y <- xs, y <= x] ++ [x] ++ qsort[y | y <- xs, y > x]

-- Create product "Person" consisting of a name and age
data Person = Person String Int deriving (Show, Eq)
name :: Person -> String
name   (Person n a) = n
age :: Person -> Int
age    (Person n a) = a 

-- Declare an order on persons (by name first then age)
instance Ord Person where
  compare x y =
    let
        d = compare (name x) (name y)
    in
        if d == EQ then compare (age x) (age y) else d

{-
-- Declare an order on persons (by age first then name)
instance Ord Person where
  compare x y =
    let
        d = compare (name x) (name y)
    in
        if d == EQ then compare (age x) (age y) else d
-}

testGenerics1 = print(qsort[4, 65, 2, -31, 0, 99, 2, 83, 782, 1])

testGenerics2 = print(qsort[645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26])

testGenerics3 = print(qsort['z', 'y', 'a', 't', 'p', 'q', 'l', 'k']);

testGenerics4 = print(qsort["apple", "zebra", "turtle", "yellow", "quest", "buffalo", "elephant"])

testGenerics5 = print (qsort[Person "Hal" 20,
							 Person "Susann" 31,
							 Person "Dwight" 19, 
							 Person "Kassandra" 21, 
							 Person "Lawrence" 25,
                   			 Person "Cindy" 22, 
                   			 Person "Cory" 27, 
                   			 Person "Mac" 19,
                   			 Person "Romana" 27, 
                   			 Person "Doretha" 32,
                   			 Person "Danna" 20, 
                   			 Person "Zara" 23, 
                   			 Person "Rosalyn" 26, 
                   			 Person "Risa" 24, 
                   			 Person "Benny" 28,
                   			 Person "Juan" 33, 
                   			 Person "Natalie" 25])