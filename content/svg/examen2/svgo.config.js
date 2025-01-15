module.exports = {
    multipass: true,        // boolean. false by default
    collapseGroups: true,   // collapse useless groups
    cleanupIDs: true,       // remove unused and minify used IDs
    convertTransform: true, // collapse multiple transforms into one, convert matrices to the short aliases, and much more
    convertStyleToAttrs: true, // convert styles into attributes
    convertColors: false,
    js2svg: {
      indent: 2,            // string with spaces or number of spaces. 4 by default
      pretty: true,         // boolean, false by default
    },
  };