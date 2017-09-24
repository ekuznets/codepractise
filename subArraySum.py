def xarr(x):
    y = []
    z = []
    maxSum = 0
    for i in xrange(len(x)):
        y = []
        for i+j in xrange(len(x)):
            y.append(x[i+j])
            if( sum(y) > maxSum):
                maxSum = sum(y)
                z = y
    print z


a = [1,-2,4,12,-9,5,-2]

xarr(a)
