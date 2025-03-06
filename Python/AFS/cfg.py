import random
import logging

#logging config
logging.basicConfig(filename='cfg.log', filemode='a', format='%(name)s - %(levelname)s - %(message)s', level=logging.INFO)

class CFG:
    def __init__(self):
        self.rules = {}
    
    def add_rules(self,symbol, replacement):
        if symbol in self.rules:
            self.rules[symbol].append(replacement)
            logging.info("appending rule(s): %s->%s", symbol, replacement)
        else:
            self.rules[symbol] = replacement
            logging.info("adding rule(s): %s->%s", symbol, replacement)

    def generate(self, start, maxdepth):
        if start in self.rules:
            str = random.choice(self.rules[start])
            logging.info("startsymbol: %s", start)
        else:
            logging.error("Error: input %s is not the start symbol", start)
            return start
        
        while(maxdepth>0):

            for i in range(0, len(str)):

                if str[i].isupper():

                    if str[i] in self.rules:
                        replacement = random.choice(self.rules[str[i]])
                        str = str[:i]+replacement+str[i+1:]
                        logging.info('%s',str)
                        break
                    else:
                        logging.error("Error: grammar incomplete, no rule for %s", str[i])
                        return str
                        
            maxdepth -= 1           

cfg = CFG()

cfg.add_rules('A', ['AB', 'CD', 'a'])
cfg.add_rules('B', ['BD', 'c'])
cfg.add_rules('C', ['a', 'b'])
cfg.add_rules('D', ['AB', 'd'])
 
for i in range(0, 20):
    cfg.generate('A', 5)
    print('\n')