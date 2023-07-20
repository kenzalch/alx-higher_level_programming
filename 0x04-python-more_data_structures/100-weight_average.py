#!/usr/bin/python3
def weight_average(my_list=[]):
    if not my_list:
        return 0

    nm = 0
    dn = 0

    for tup in my_list:
        nm += tup[0] * tup[1]
        dn += tup[1]

    return (nm / dn)
