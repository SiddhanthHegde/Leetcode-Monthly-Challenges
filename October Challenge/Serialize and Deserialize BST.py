# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def __init__(self):
        self.s = ""
    
    def preorder(self,root):
        if root is not None:
            self.s += str(root.val) + ','
            self.preorder(root.left)
            self.preorder(root.right)
            
    
    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        self.preorder(root)
        #print(self.s)
        return '[' + self.s[:-1] + ']'
        

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        v = []
        if data == '[]':
            return None
        for num in data[1:-1].split(','):
            v.append(int(num))
        return self.bst(v)
    
    def bst(self, v):
        n = len(v)
        l, r = [], []
        if n == 0:
            return None
        root = TreeNode(v[0])
        for x in v[1:]:
            if x < root.val:
                l.append(x)
            else:
                r.append(x)
        root.left = self.bst(l)
        root.right = self.bst(r)
        return root
        

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans