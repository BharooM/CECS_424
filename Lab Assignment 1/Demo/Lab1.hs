-- qsort is a function I created which uses the Ord class
-- qsort takes in a list and returns a sorted list
qsort :: Ord a => [a] -> [a]

-- If qsort is called with an empty list, return an empty list.
qsort [] = []

-- Otherwise, if qsort is called with a non-empty list (x:xs)...
    -- x being the first element in the list
    -- xs being the rest of the list

-- We get a list of all elements in the list xs that are less than or equal to x
    -- [y | y <- xs, y <= x]

-- Then get a list of all elements in the list xs that are greater than x
    -- [y | y <- xs, y > x]

-- And lastly, concatenate the resulting lists with a single element list [x]
    -- ++ [x] ++
qsort (x:xs) = qsort[y | y <- xs, y <= x] ++ [x] ++ qsort[y | y <- xs, y > x]

--main = print(qsort[4, 65, 2, -31, 0, 99, 2, 83, 782, 1])


----------------------------------------------------------------------------------------------------

-- divide is function I created that takes in a list, splits it in half, and returns two lists
divide :: [a] -> ([a], [a])

-- After calculating half the length of the list...
-- Use the standard functions 'take' and 'drop'
    -- 'take n xs' serves to store the first half the of the imported list into a new list
    -- 'drop n xs' stores the second half into a new list
divide xs = (take n xs, drop n xs)
    where n = (length xs) `div` 2

-- merge is a function I created which uses the Ord class
-- merge takes in two lists and returns a single sorted list
merge :: (Ord a) => [a] -> [a] -> [a]

-- If the first list is empty, only the second list is returned
merge [] xs = xs

-- If the second list is empty, only the first list is returned
merge xs [] = xs

-- Otherwise, if merge is called with two non-empty lists (x:xs) and (y:ys)...
-- We compare the first elements in each list
-- The least of the two are put into a new list
-- This repeats until all elements in both lists have been compared and appended to the new sorted list
merge (x:xs) (y:ys)
    | (x < y) = x:merge xs (y:ys)
    | otherwise = y:merge (x:xs) ys

-- msort is a function I created that uses the Ord class
-- msort takes in a list and returns a list
msort :: Ord a => [a] -> [a]

-- If the length of the list is > 1...
    -- Split the list in two using the 'divide' function above.
    -- And merge those two lists recursively until length is less than or equal to 1.
-- Otherwise, return the list
msort xs
    | (length xs) > 1 = merge (msort ls) (msort rs)
    | otherwise = xs
    where (ls, rs) = divide xs

main = print(msort[4, 65, 2, -31, 0, 99, 2, 83, 782, 1])