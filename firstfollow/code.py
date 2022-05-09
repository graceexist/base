def add_dict(d,k,l):
    d[k]=list()
    d[k].extend(l)
    return d

prod = {} 
n=int(input("Enter the number of non-terminals: "))
key = input("Enter the non-terminal: ")
start=key
for i in range (0,n):
    rhs=[]
    x=int(input("Enter no of terms on rhs: "))
    for j in range (0,x):
        value = input("Enter RHS term: ")
        rhs.append(value)
    prod=add_dict(prod,key,rhs)
    if(i!=n-1):
        key = input("Enter the non-terminal:")
    

result = prod
print("\nDictionary of Production rules:",result,"\n\n")

terminals= []
for i in result:
    for j in result[i]:
        for k in j:
            if k not in result:
                terminals+=[k]
terminals = list(set(terminals))
print("List of terminals:",terminals)
print("\n")

def first(gram, lhs):
    f = []
    if lhs not in gram:
        return [lhs]
    for i in gram[lhs]:
        if i[0] not in gram:
            f.append(i[0])
        elif i[0] in gram:
            f += first(gram, i[0])
    return f

firsts = {}
for i in result:
    firsts[i] = first(result,i)
    print(f'First({i}):',firsts[i])

def follow(gram, term,start):
    a = []
    for rule in gram:
        if rule == start:
            a+=['$']
        for i in gram[rule]:
            if term in i:
                temp = i
                indx = i.index(term)
                if indx+1!=len(i):
                    if i[-1] in firsts:
                        a+=firsts[i[-1]]
                    else:
                        a+=[i[-1]]
                else:
                    a+=["e"]
                if rule != term and "e" in a:
                    a+= follow(gram,rule,start)
    
    return a
print('\n\n')
follows = {}
x=0
for i in result:
    follows[i] = list(set(follow(result,i,start)))
    if "e" in follows[i]:
        follows[i].pop(follows[i].index("e"))
    print(f'Follow({i}):',follows[i])

print('\n\n')
tterm = list(terminals)
tterm.pop(tterm.index("e"))
tterm+=["$"]
table = {}

for i in result:
    for j in tterm:
        if j in firsts[i]:
            table[(i,j)]=result[i[0]][0]
            #print(result[i[0]][0])
        else:
            table[(i,j)]=""
    if "e" in firsts[i]:
        for j in tterm:
            if j in follows[i]:
                table[(i,j)]="e" 

toprint = f'{"": <10}'

for i in tterm:
    toprint+= f'|{i: <10}'
print(toprint)

for i in result:
    toprint = f'{i: <10}'
    for j in tterm:
        if table[(i,j)]!="":
            toprint+=f'|{i+"->"+table[(i,j)]: <10}'
        else:
            toprint+=f'|{table[(i,j)]: <10}'
    print(f'{"-":-<76}')
    print(toprint)
