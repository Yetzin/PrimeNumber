class NumberList
{
    static instance;

    _list = [];

    constructor() {
        if ( !!NumberList.instance ) {
            return NumberList.instance;
        }

        NumberList.instance = this;
    }

    get list() {
        return this._list;
    }

    set list(value) {
        this._list = value;
    }
}

module.exports = NumberList;
