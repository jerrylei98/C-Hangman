#used only to make the string to copy and paste into c program
def divide_by_dash(string):
    hold = string.split('\n')
    c1 = 0
    string_word = "char *words[" + str(len(hold)) + "] = {"
    string_definition = "char *definitions[" + str(len(hold)) + "] = {"
    while c1 < len(hold) - 1:
        string_word += '"' + hold[c1].split(' - ')[0] + '"' + ", "
        string_definition += '"' + hold[c1].split(' - ')[1] + '"' + ", "
        c1 += 1
    string_word += '"' + hold[c1].split(' - ')[0] + '"};'
    string_definition += '"' + hold[c1].split(' - ')[0] + '"};'
    return string_word + "\n" + string_definition


print divide_by_dash("""abbreviate - shorten, abridge
abstinence - act of refraining from
adulation - high praise
adversity - misfortune
aesthetic - pertaining to beauty
amicable - agreeable
anachronistic - out-of-date
anecdote - short account of event
anonymous - nameless
antagonist - opponent
arid - extremely dry
assiduous - hard-working
asylum - sanctuary
benevolent - friendly, helpful
camaraderie - trust among friends
censure - to criticize harshly
circuitous - indirect, roundabout
clairvoyant - able to see the future
collaborate - to work together
compassion - sympathy, mercy
compromise - to settle differences
condescending - patronizing
conditional - provisional, contingent
conformist - follower of customs
congregation - crowd of people
convergence - joining of parts
deleterious - harmful
demagogue - rabble-rousing leader
digression - straying from main point
diligent - hard-working
discredit - dishonor, disgrace
disdain - to regard with scorn
divergent - variant, moving apart
empathy - sharing of feelings
emulate - follow an example
enervating - tiring, weakening
enhance - improve, augment
ephemeral - momentary, fleeting
evanescent - short-lived, as an image
exasperation - irritation, frustration
exemplary - outstanding
extenuating - guilt diminishing
florid - flushed, ornate
fortuitous - lucky
frugal - thrifty
hackneyed - overused, cliched
haughty - arrogant, condescending
hedonist - pleasure seeker
hypothesis - theory requiring proof
impetuous - rash, impulsive
impute - to attribute to someone
incompatible - unable to work together
inconsequential - trivial
inevitable - unavoidable, certain
integrity - honesty, decency
intrepid - fearless, adventurous
intuitive - instinctive, untaught
jubilation - joy, exultation
lobbyist - persuader of legislators
longevity - long life
mundane - ordinary, common
nonchalant - calm, casual
novice - beginner
opulent - wealthy
orator - speaker
ostentatious - displaying wealth
parched - dried up
perfidious - disloyal
precocious - talented beyond one's age
pretentious - pompous, self-important
procrastinate - to delay unnecessarily
prosaic - run-of-the-mill
prosperity - wealth, success
provocative - inflammatory
prudent - wise, careful, cautious
querulous - irritable
rancorous - hateful
reclusive - withdrawn, hermit-like
reconciliation - agreement after a quarrel
renovation - state of being renewed
resilient - quick to recover
restrained - controlled, restricted
reverence - profound respect
sagacity - wisdom
scrutinize - to observe carefully
spontaneity - impulsive action
spurious - phony, false
submissive - meek
substantiate - to verify, confirm
subtle - elusive, sly, ambiguous
superficial - lacking in depth
superfluous - more than enough
suppress - to end an activity
surreptitious - secret, stealthy
tactful - diplomatic, polite
tenacious - persistent, resolute
transient - temporary, fleeting
venerable - respectable due to age
vindicate - to clear from blame
wary - watchful, alert""")
