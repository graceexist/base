def is_number(s):
    try:
        float(s)
        return True
    except:
        return False

file=open(r"C:\Users\shubh\Documents\Shubhankita\Semester_VI\C]CompilerDesign\Practical\Exp2-Lexica-Analyser\test.txt")
lines = file.readlines()

keywords = ['include','iostream','using','namespace','std','class','public','int','string','main','cout','endl','return']

operators = ['+','-','*','/','%','==','!=','.','>','<','>=','<=','&&','||','!','&','|','^','~','>>','<<','=','+=','-=','*=']

special_symbol = ['@','#','$','_','!','//','/*','*/','"',"'"]

separator = [',',':',';','\n','\t','{','}','(',')','[',']']

for line in lines:
    for i in line.strip().split(" "):
        if i in keywords:
            print (i, " is a keyword")
        elif i in operators:
            print (i, " is an operator")
        elif i in separator:
            print (i, " is a punctuation")
        elif i in special_symbol:
            print (i, " is a special symbol")
        elif is_number(i):
            print (i, " is a number")
        else:
            print (i, " is an identifier")
