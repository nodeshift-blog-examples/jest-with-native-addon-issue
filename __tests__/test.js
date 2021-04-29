const addon = require('bindings')('hello');

describe('test suite 1', () => {
  test('exception', () => {
    expect(addon.exception()).toThrow(TypeError);
  });
});
