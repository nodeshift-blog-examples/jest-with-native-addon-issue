const addon = require('bindings')('hello');
const assert = require('assert');
const { after, before, describe, it } = require('mocha');

describe('test suite 1', () => {
  it('exception', () => {
    try {
      addon.exception()
    } catch (err) {
      assert(err instanceof TypeError) 
    }
  });
});
