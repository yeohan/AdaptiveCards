"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var Collection = (function () {
    function Collection() {
        this._items = [];
        this.onItemAdded = null;
        this.onItemRemoved = null;
    }
    Collection.prototype.get = function (index) {
        return this._items[index];
    };
    Collection.prototype.add = function (item) {
        this._items.push(item);
        if (this.onItemAdded) {
            this.onItemAdded(item);
        }
    };
    Collection.prototype.remove = function (item) {
        var i = this._items.indexOf(item);
        if (i >= 0) {
            this._items = this._items.splice(i, 1);
            if (this.onItemRemoved) {
                this.onItemRemoved(item);
            }
        }
    };
    Collection.prototype.indexOf = function (item) {
        return this._items.indexOf(item);
    };
    Object.defineProperty(Collection.prototype, "length", {
        get: function () {
            return this._items.length;
        },
        enumerable: true,
        configurable: true
    });
    return Collection;
}());
exports.Collection = Collection;
//# sourceMappingURL=collection.js.map