op=set(['+','-','*','/','^','(',')'])
p={
    '+':1,
    '-':1,
    '*':2,
    '/':2,
    '^':3
}

def postfix(e):
    stack=[]
    o=''
    
    for c in e:
        if c not in op:
            o+=c
        elif c=='(':
            stack.append('(')
        elif c==')':
            while stack and stack[-1] !='(':
                o+=stack.pop()
            stack.pop()
        else:
            while stack and stack[-1]!='(' and p[c]<=p[stack[-1]]:
                o+=stack.pop()
            stack.append(c)
    while stack:
        o+=stack.pop()
    return o

def prefix(e):
    st=[]
    o=[]
    
    for c in e:
        if c not in op:
            o.append(c)
        elif c=='(':
            st.append(c)
        elif c==')':
            while st[-1]!='(':
                x=st.pop()
                a=o.pop()
                b=o.pop()
                o.append(x+b+a)
            st.pop()
        else:
            while st and st[-1]!='(' and p[c]<=p[st[-1]]:
                x=st.pop()
                a=o.pop()
                b=o.pop()
                o.append(x+b+a)
            st.append(c)
    while st:
        x=st.pop()
        a=o.pop()
        b=o.pop()
        o.append(x+b+a)
    print('Prefix Expression: ',o[-1])
    
x=input('Enter the expression: ')
print('Postfix Notation: ',postfix(x))
prefix(x)
