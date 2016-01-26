#used only to make the string to copy and paste into c program
def divide_by_dash(string, dividing_char):
    hold = string.split('\n')
    c1 = 0
    string_word = "char *words[" + str(len(hold)) + "] = {"
    string_definition = "char *definitions[" + str(len(hold)) + "] = {"
    while c1 < len(hold) - 1:
        string_word += '"' + hold[c1].split(dividing_char)[0] + '"' + ", "
        string_definition += '"' + hold[c1].split(dividing_char)[1] + '"' + ", "
        c1 += 1
    string_word += '"' + hold[c1].split(dividing_char)[0] + '"};'
    string_definition += '"' + hold[c1].split(dividing_char)[0] + '"};'
    return string_word + "\n" + string_definition


#separation_type = raw_input("Input dividing character:")
#word_list = raw_input("Input word list:")
separation_type = ","
word_list = ""

divide_by_dash(word_list, separation_type)
