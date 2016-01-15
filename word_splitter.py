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
word_list = """Majority Rule,A fundamental democratic principle requiring that the majority's view be respected. Nonetheless, the Constitution originally contained a number of provisions designed to limit majority rule, including the electoral college, life tenor for Supreme Court justices, and the selection of senators by state legislators.
Checks and Balances,System in which each branch of government can limit the power of the other two branches. For example, the Senate has the power to approve or reject presidential appointments to the Supreme Court.
Unitary System,System of government in which all power is invested in a central government.
Federalism,A system of government in which power is divided by a written constitution between a central government and regional governments. As a result, two or more levels of government have formal authority over the same geographic area and people.
Expressed/Enumerated Powers,Powers specifically granted to the federal government by the Constitution. For example, the Constitution gives Congress the power to coin money, impose taxes, and regulate interstate commerce. Expressed powers are also called enumerated powers.
Implied Powers,Powers of the federal government that go beyond those enumerated in the Constitution. Implied powers are derived from the elastic or necessary and proper clause.
Reserved Powers,Powers not specifically granted to the national government or denied to the states. Reserved powers are held by the states through the Tenth Amendment.
Direct Democracy,Government in which citizens vote on laws and select officials directly. Full participation.
Representative Democracy,Government in which the people elect those who govern and pass laws; also called a republic. Citizens pick representatives to make decisions.
Majoritarian Theory (Democratic Theory),Democracy based upon majority rule of a society's citizens. Majoritarian democracy is the conventional form of democracy used as a political system in many countries.
Pluralist Theory,Theory that democracy can be achieved through competition among multiple organized groups and that individuals can participate in politics through group memberships and elections.
Hyperpluralism,A theory of government and polities contending that groups are so strong that government is weakened. Hyerpluralism is an extreme, exaggerated, or perverted form of pluralism. Compare elite and class theory, pluralist theory, and traditional democratic theory.
Elite/Class Theory,A theory of government and politics contending that societies are divided along class lines and that an upper-class elite will rule, regardless of the formal niceties of governmental organization. Compare hyper pluralism, pluralist theory, and traditional democratic theory.
Marxist Theory,There are owners and workers competing for power; whoever controls the economy controls the government.
Federalists,Those that supported the new Constitution and its form of a strong, central government.
Anti-Federalists,An individual who opposed the ratification of the new Constitution in 1787; opposed to a strong central government.
Factions,Madisonian idea of a group of citizens who unite together because they have a common impulse of passion, interests, and ideas.
Judicial Review,Authority given the courts to review constitutionality of acts by the executive/state/legislature; est. in Marbury v. Madison.
Elastic Clause,The necessary &proper clause/Art. I, Sec. 8, Clause 18/imlied powers clause- that allows Congress to pass laws to carry out its powers.
Supremacy Clause,National law supersedes all other laws passed by states (Art VI of Constitution).
Full Faith & Credit Clause,States are required to recognize the laws & legal documents of other states (Article IV of Constitution)."""


print divide_by_dash(word_list, separation_type)
