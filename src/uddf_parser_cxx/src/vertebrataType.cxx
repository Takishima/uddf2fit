// Copyright (c) 2005-2023 Code Synthesis.
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis gives permission
// to link this program with the Xerces-C++ library (or with modified
// versions of Xerces-C++ that use the same license as Xerces-C++), and
// distribute linked combinations including the two. You must obey the GNU
// General Public License version 2 in all respects for all of the code
// used other than Xerces-C++. If you modify this copy of the program, you
// may extend this exception to your version of the program, but you are
// not obligated to do so. If you do not wish to do so, delete this
// exception statement from your version.
//
// Furthermore, Code Synthesis makes a special exception for the Free/Libre
// and Open Source Software (FLOSS) which is described in the accompanying
// FLOSSE file.
//

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "vertebrataType.hxx"

#include "singleLifeFormType.hxx"

namespace streit
{
  // vertebrataType
  //

  const vertebrataType::chondrichthyes_optional& vertebrataType::
  chondrichthyes () const
  {
    return this->chondrichthyes_;
  }

  vertebrataType::chondrichthyes_optional& vertebrataType::
  chondrichthyes ()
  {
    return this->chondrichthyes_;
  }

  void vertebrataType::
  chondrichthyes (const chondrichthyes_type& x)
  {
    this->chondrichthyes_.set (x);
  }

  void vertebrataType::
  chondrichthyes (const chondrichthyes_optional& x)
  {
    this->chondrichthyes_ = x;
  }

  void vertebrataType::
  chondrichthyes (::std::unique_ptr< chondrichthyes_type > x)
  {
    this->chondrichthyes_.set (std::move (x));
  }

  const vertebrataType::osteichthyes_optional& vertebrataType::
  osteichthyes () const
  {
    return this->osteichthyes_;
  }

  vertebrataType::osteichthyes_optional& vertebrataType::
  osteichthyes ()
  {
    return this->osteichthyes_;
  }

  void vertebrataType::
  osteichthyes (const osteichthyes_type& x)
  {
    this->osteichthyes_.set (x);
  }

  void vertebrataType::
  osteichthyes (const osteichthyes_optional& x)
  {
    this->osteichthyes_ = x;
  }

  void vertebrataType::
  osteichthyes (::std::unique_ptr< osteichthyes_type > x)
  {
    this->osteichthyes_.set (std::move (x));
  }

  const vertebrataType::mammalia_optional& vertebrataType::
  mammalia () const
  {
    return this->mammalia_;
  }

  vertebrataType::mammalia_optional& vertebrataType::
  mammalia ()
  {
    return this->mammalia_;
  }

  void vertebrataType::
  mammalia (const mammalia_type& x)
  {
    this->mammalia_.set (x);
  }

  void vertebrataType::
  mammalia (const mammalia_optional& x)
  {
    this->mammalia_ = x;
  }

  void vertebrataType::
  mammalia (::std::unique_ptr< mammalia_type > x)
  {
    this->mammalia_.set (std::move (x));
  }

  const vertebrataType::amphibia_optional& vertebrataType::
  amphibia () const
  {
    return this->amphibia_;
  }

  vertebrataType::amphibia_optional& vertebrataType::
  amphibia ()
  {
    return this->amphibia_;
  }

  void vertebrataType::
  amphibia (const amphibia_type& x)
  {
    this->amphibia_.set (x);
  }

  void vertebrataType::
  amphibia (const amphibia_optional& x)
  {
    this->amphibia_ = x;
  }

  void vertebrataType::
  amphibia (::std::unique_ptr< amphibia_type > x)
  {
    this->amphibia_.set (std::move (x));
  }

  const vertebrataType::reptilia_optional& vertebrataType::
  reptilia () const
  {
    return this->reptilia_;
  }

  vertebrataType::reptilia_optional& vertebrataType::
  reptilia ()
  {
    return this->reptilia_;
  }

  void vertebrataType::
  reptilia (const reptilia_type& x)
  {
    this->reptilia_.set (x);
  }

  void vertebrataType::
  reptilia (const reptilia_optional& x)
  {
    this->reptilia_ = x;
  }

  void vertebrataType::
  reptilia (::std::unique_ptr< reptilia_type > x)
  {
    this->reptilia_.set (std::move (x));
  }

  const vertebrataType::vertebratavarious_optional& vertebrataType::
  vertebratavarious () const
  {
    return this->vertebratavarious_;
  }

  vertebrataType::vertebratavarious_optional& vertebrataType::
  vertebratavarious ()
  {
    return this->vertebratavarious_;
  }

  void vertebrataType::
  vertebratavarious (const vertebratavarious_type& x)
  {
    this->vertebratavarious_.set (x);
  }

  void vertebrataType::
  vertebratavarious (const vertebratavarious_optional& x)
  {
    this->vertebratavarious_ = x;
  }

  void vertebrataType::
  vertebratavarious (::std::unique_ptr< vertebratavarious_type > x)
  {
    this->vertebratavarious_.set (std::move (x));
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // vertebrataType
  //

  vertebrataType::
  vertebrataType ()
  : ::xml_schema::type (),
    chondrichthyes_ (this),
    osteichthyes_ (this),
    mammalia_ (this),
    amphibia_ (this),
    reptilia_ (this),
    vertebratavarious_ (this)
  {
  }

  vertebrataType::
  vertebrataType (const vertebrataType& x,
                  ::xml_schema::flags f,
                  ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    chondrichthyes_ (x.chondrichthyes_, f, this),
    osteichthyes_ (x.osteichthyes_, f, this),
    mammalia_ (x.mammalia_, f, this),
    amphibia_ (x.amphibia_, f, this),
    reptilia_ (x.reptilia_, f, this),
    vertebratavarious_ (x.vertebratavarious_, f, this)
  {
  }

  vertebrataType::
  vertebrataType (const ::xercesc::DOMElement& e,
                  ::xml_schema::flags f,
                  ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    chondrichthyes_ (this),
    osteichthyes_ (this),
    mammalia_ (this),
    amphibia_ (this),
    reptilia_ (this),
    vertebratavarious_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void vertebrataType::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // chondrichthyes
      //
      if (n.name () == "chondrichthyes" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< chondrichthyes_type > r (
          chondrichthyes_traits::create (i, f, this));

        if (!this->chondrichthyes_)
        {
          this->chondrichthyes_.set (::std::move (r));
          continue;
        }
      }

      // osteichthyes
      //
      if (n.name () == "osteichthyes" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< osteichthyes_type > r (
          osteichthyes_traits::create (i, f, this));

        if (!this->osteichthyes_)
        {
          this->osteichthyes_.set (::std::move (r));
          continue;
        }
      }

      // mammalia
      //
      if (n.name () == "mammalia" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< mammalia_type > r (
          mammalia_traits::create (i, f, this));

        if (!this->mammalia_)
        {
          this->mammalia_.set (::std::move (r));
          continue;
        }
      }

      // amphibia
      //
      if (n.name () == "amphibia" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< amphibia_type > r (
          amphibia_traits::create (i, f, this));

        if (!this->amphibia_)
        {
          this->amphibia_.set (::std::move (r));
          continue;
        }
      }

      // reptilia
      //
      if (n.name () == "reptilia" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< reptilia_type > r (
          reptilia_traits::create (i, f, this));

        if (!this->reptilia_)
        {
          this->reptilia_.set (::std::move (r));
          continue;
        }
      }

      // vertebratavarious
      //
      if (n.name () == "vertebratavarious" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< vertebratavarious_type > r (
          vertebratavarious_traits::create (i, f, this));

        if (!this->vertebratavarious_)
        {
          this->vertebratavarious_.set (::std::move (r));
          continue;
        }
      }

      break;
    }
  }

  vertebrataType* vertebrataType::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class vertebrataType (*this, f, c);
  }

  vertebrataType& vertebrataType::
  operator= (const vertebrataType& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->chondrichthyes_ = x.chondrichthyes_;
      this->osteichthyes_ = x.osteichthyes_;
      this->mammalia_ = x.mammalia_;
      this->amphibia_ = x.amphibia_;
      this->reptilia_ = x.reptilia_;
      this->vertebratavarious_ = x.vertebratavarious_;
    }

    return *this;
  }

  vertebrataType::
  ~vertebrataType ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const vertebrataType& i)
  {
    if (i.chondrichthyes ())
    {
      o << ::std::endl << "chondrichthyes: " << *i.chondrichthyes ();
    }

    if (i.osteichthyes ())
    {
      o << ::std::endl << "osteichthyes: " << *i.osteichthyes ();
    }

    if (i.mammalia ())
    {
      o << ::std::endl << "mammalia: " << *i.mammalia ();
    }

    if (i.amphibia ())
    {
      o << ::std::endl << "amphibia: " << *i.amphibia ();
    }

    if (i.reptilia ())
    {
      o << ::std::endl << "reptilia: " << *i.reptilia ();
    }

    if (i.vertebratavarious ())
    {
      o << ::std::endl << "vertebratavarious: " << *i.vertebratavarious ();
    }

    return o;
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace streit
{
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

