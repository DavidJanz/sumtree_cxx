from sumtree import SumTree

st = SumTree(10)

print("len", len(st), "contents:", [st[i] for i in range(len(st))])

st.append(1, 2)
print("len", len(st), "contents:", [st[i] for i in range(len(st))])

st.append(2, 1)
print("len", len(st), "contents:", [st[i] for i in range(len(st))])

st.append(3, 4)
print("len", len(st), "contents:", [st[i] for i in range(len(st))])
