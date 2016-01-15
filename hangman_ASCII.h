#include <fcntl.h>

int rand_num(int DIVIDE){
  int c = open("/dev/urandom", O_RDONLY);
  unsigned int num;
  read(c,&num,4);
  close(c);
  return num % DIVIDE;
}

char *hangman_numbers[7] = {
"\
\n +---+\
\n |   |\
\n     |\
\n     |\
\n     |\
\n     |\
\n========\n", 

"\
\n +---+\
\n |   |\
\n O   |\
\n     |\
\n     |\
\n     |\
\n========\n",

"\
\n +---+\
\n |   |\
\n O   |\
\n |   |\
\n     |\
\n     |\
\n========\n",

"\
\n +---+\
\n |   |\
\n O   |\
\n/|   |\
\n     |\
\n     |\
\n========\n",

"\
\n +---+\
\n |   |\
\n O   |\
\n/|\\  |\
\n     |\
\n     |\
\n========\n",

"\
\n +---+\
\n |   |\
\n O   |\
\n/|\\  |\
\n |   |\
\n/    |\
\n========\n",

"\
\n +---+\
\n |   |\
\n O   |\
\n/|\\  |\
\n |   |\
\n/ \\  |\
\n========\n"

};

int max_words = 21;

char *words[21] = {"Majority Rule", "Checks and Balances", "Unitary System", "Federalism", "Expressed/Enumerated Powers", "Implied Powers", "Reserved Powers", "Direct Democracy", "Representative Democracy", "Majoritarian Theory (Democratic Theory)", "Pluralist Theory", "Hyperpluralism", "Elite/Class Theory", "Marxist Theory", "Federalists", "Anti-Federalists", "Factions", "Judicial Review", "Elastic Clause", "Supremacy Clause", "Full Faith & Credit Clause"};


char *definitions[21] = {"A fundamental democratic principle requiring that the majority's view be respected. Nonetheless", "System in which each branch of government can limit the power of the other two branches. For example", "System of government in which all power is invested in a central government.", "A system of government in which power is divided by a written constitution between a central government and regional governments. As a result", "Powers specifically granted to the federal government by the Constitution. For example", "Powers of the federal government that go beyond those enumerated in the Constitution. Implied powers are derived from the elastic or necessary and proper clause.", "Powers not specifically granted to the national government or denied to the states. Reserved powers are held by the states through the Tenth Amendment.", "Government in which citizens vote on laws and select officials directly. Full participation.", "Government in which the people elect those who govern and pass laws; also called a republic. Citizens pick representatives to make decisions.", "Democracy based upon majority rule of a society's citizens. Majoritarian democracy is the conventional form of democracy used as a political system in many countries.", "Theory that democracy can be achieved through competition among multiple organized groups and that individuals can participate in politics through group memberships and elections.", "A theory of government and polities contending that groups are so strong that government is weakened. Hyerpluralism is an extreme", "A theory of government and politics contending that societies are divided along class lines and that an upper-class elite will rule", "There are owners and workers competing for power; whoever controls the economy controls the government.", "Those that supported the new Constitution and its form of a strong", "An individual who opposed the ratification of the new Constitution in 1787; opposed to a strong central government.", "Madisonian idea of a group of citizens who unite together because they have a common impulse of passion", "Authority given the courts to review constitutionality of acts by the executive/state/legislature; est. in Marbury v. Madison.", "The necessary &proper clause/Art. I", "National law supersedes all other laws passed by states (Art VI of Constitution).", "Full Faith & Credit Clause"};

