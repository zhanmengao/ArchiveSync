package f9log

type tagMap map[string]string

func newTagMap() tagMap {
	return make(tagMap, 10)
}

func (m tagMap) Reset() {
	for k, _ := range m {
		delete(m, k)
	}
}
