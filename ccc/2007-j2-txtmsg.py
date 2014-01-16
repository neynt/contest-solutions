# Declare and populate a dictionary of translations.
#
# A dictionary (a.k.a. associative array, map) is a python object
# (usually denoted by curly brackets) that lets you "look up" any
# object given another object very quickly. The lookup is very
# fast -- about log(n) time.
translation = {
    'CU': "see you",
    ':-)': "I'm happy",
    ':-(': "I'm unhappy",
    ';-)': "wink",
    ':-P': "stick out my tongue",
    '(~.~)': "sleepy",
    'TA': "totally awesome",
    'CCC': "Canadian Computing Competition",
    'CUZ': "because",
    'TY': "thank-you",
    'YW': "you're welcome",
    'TTYL': "talk to you later"
}

# Python doesn't have do-while, so we use an infinite loop that we
# break out of when the user enters 'TTYL'.
while True:
    word = input('Enter phrase> ')

    # This is a concise way to write
    #
    # if word in translation:
    #     print(translation[word])
    # else:
    #     print(word)
    print(translation[word] if word in translation else word)

    if word == 'TTYL': break
