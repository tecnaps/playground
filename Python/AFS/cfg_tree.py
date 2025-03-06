import logging

logging.basicConfig(filename='cfg_tree.log', filemode='a', format='%(name)s - %(levelname)s - %(message)s', level=logging.INFO)


class Node:
    def __init__(self, symbol, parent):

        self.symbol = symbol
        self.parent = parent
        self.children = []

        if parent is None:
            self.depth = 0
        else:
            self.depth = parent.depth+1


    def add_child(self, node):
        self.children.append(node)

class CFG:
    
    def __init__(self, depth):
        self.maxDepth = depth
        self.rules = {}

    def __init__(self):
        self.maxDepth = 10
        self.rules = {}

    def add_rules(self,symbol: str, replacement: str):
        if symbol in self.rules:
            self.rules[symbol].append(replacement)
            logging.info("appending rule(s): %s->%s", symbol, replacement)
        else:
            self.rules[symbol] = replacement
            logging.info("adding rule(s): %s->%s", symbol, replacement)

    def parse(self, current: Node):

        if current == None or current.depth > self.maxDepth:
            return

        for i in range (0, len(current.symbol)):
            
            if current.symbol[i].isupper():

                replacement = self.rules[current.symbol[i]]
                
                for rep in replacement:

                    str = current.symbol[:i]+rep+current.symbol[i+1:]
                    child = current.add_child(Node(str, current))
                    logging.info("%s->%s", current.symbol, str)
                    self.parse(child)
                

    def generate(self, symbol: str):
        
        if symbol not in self.rules:
            logging.error("%s is not a valid non-terminal", symbol)
            return None

        root = Node(symbol, None)

        replacements = self.rules[symbol]

        for rep in replacements:
            root.add_child(Node(rep, root))
            logging.info("%s->%s", symbol, rep)    

        for child in root.children:
            self.parse(child)

        return root


cfg = CFG()

cfg.add_rules('A', ['AB', 'CD', 'a'])
cfg.add_rules('B', ['BD', 'c'])
cfg.add_rules('C', ['a', 'b'])
cfg.add_rules('D', ['AB', 'd'])

root = cfg.generate('A')