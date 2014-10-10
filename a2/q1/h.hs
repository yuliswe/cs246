import Text.Read

getInt:: IO Int
getInt = do {
    x <- getLine;
    case readMaybe x of
        Just x  -> return x
        Nothing -> do {print "That's not an integer"; getInt}
}

calculateChanges:: Int -> [Int]
calculateChanges x = [a,b,c,d,e,f]
    where
        (a,r)   = quotRem x 200
        (b,r1)  = quotRem r 100
        (c,r2)  = quotRem r1 25
        (d,r3)  = quotRem r2 10
        (e,f)   = quotRem r3 5

main = do {
    print "Enter an interger";
    x <- getInt;
    case calculateChanges x 
    of [a,b,c,d,e,f] -> do
        putStrLn $ "toonie(s):  " ++show a
        putStrLn $ "loonie(s):  " ++show b
        putStrLn $ "quarter(s): " ++show c
        putStrLn $ "dime(s):    " ++show d
        putStrLn $ "nickel(s):  " ++show e
        putStrLn $ "cent(s):    " ++show f
}
