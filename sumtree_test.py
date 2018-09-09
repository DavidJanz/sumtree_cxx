import sumtree

st = sumtree.SumTree()

st.append(1, 2)
st.append(2, 2)
st.append(3, 4)

print("find 4", st[0])

print("front item", st.pop_front())

print("len", len(st))
